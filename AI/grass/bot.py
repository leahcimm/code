import requests
import time
from http.client import RemoteDisconnected
from urllib3.exceptions import ProtocolError
import json
from typing import Dict, Optional
import logging

# Set up logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)

class GrassBot:
    def __init__(self, api_key: str, proxy_address: str, proxy_port: int):
        """
        Initialize the Grass bot with API key and proxy settings
        
        Args:
            api_key (str): Grass API key for authentication
            proxy_address (str): Proxy IP address
            proxy_port (int): Proxy port number
        """
        self.api_key = api_key
        self.base_url = "https://api.getgrass.io"  # Hypothetical base URL
        self.session = requests.Session()
        
        # Configure proxy
        self.proxy = {
            "http": f"http://{proxy_address}:{proxy_port}",
            "https": f"http://{proxy_address}:{proxy_port}"
        }
        self.session.proxies = self.proxy
        
        # Set headers with API key
        self.session.headers.update({
            "Authorization": f"Bearer {api_key}",
            "Content-Type": "application/json",
            "User-Agent": "GrassBot/1.0"
        })

    def get_points_balance(self) -> Optional[float]:
        """
        Retrieve the current points balance from Grass API
        
        Returns:
            float: Current points balance or None if request fails
        """
        try:
            response = self.session.get(f"{self.base_url}/user/balance")
            response.raise_for_status()
            data = response.json()
            balance = data.get("points", 0.0)
            logger.info(f"Current points balance: {balance}")
            return balance
        except (requests.RequestException, ValueError) as e:
            logger.error(f"Error fetching points balance: {str(e)}")
            return None

    def start_farming(self, source: str, volume: int, duration: int) -> Dict:
        """
        Start farming points with specified parameters
        
        Args:
            source (str): Traffic source
            volume (int): Traffic volume
            duration (int): Duration in seconds
            
        Returns:
            dict: Farming result
        """
        payload = {
            "traffic_source": source,
            "traffic_volume": volume,
            "duration": duration
        }
        
        max_retries = 3
        retry_delay = 5  # seconds
        
        for attempt in range(max_retries):
            try:
                response = self.session.post(
                    f"{self.base_url}/farming/start",
                    json=payload,
                    timeout=30
                )
                response.raise_for_status()
                
                # Simulate farming duration
                logger.info(f"Starting farming for {duration} seconds...")
                time.sleep(duration)
                
                result = response.json()
                result["initial_balance"] = self.get_points_balance()
                return result
                
            except (requests.RequestException, RemoteDisconnected, ProtocolError) as e:
                logger.error(f"Attempt {attempt + 1} failed: {str(e)}")
                if attempt < max_retries - 1:
                    time.sleep(retry_delay)
                    continue
                return {
                    "success": False,
                    "error": str(e),
                    "points_earned": 0
                }

    def run(self, source: str, volume: int, duration: int) -> None:
        """
        Execute the full farming process
        
        Args:
            source (str): Traffic source
            volume (int): Traffic volume
            duration (int): Duration in seconds
        """
        # Get initial balance
        initial_balance = self.get_points_balance()
        if initial_balance is None:
            logger.error("Failed to start: Could not retrieve initial balance")
            return

        # Start farming
        result = self.start_farming(source, volume, duration)
        
        # Get final balance
        final_balance = self.get_points_balance()
        
        # Print results
        if result.get("success", False):
            points_earned = final_balance - initial_balance if final_balance is not None else result.get("points_earned", 0)
            print("\nFarming Results:")
            print(f"Status: Success")
            print(f"Traffic Source: {source}")
            print(f"Volume: {volume}")
            print(f"Duration: {duration} seconds")
            print(f"Initial Balance: {initial_balance}")
            print(f"Final Balance: {final_balance}")
            print(f"Points Earned: {points_earned}")
        else:
            print("\nFarming Results:")
            print(f"Status: Failed")
            print(f"Error: {result.get('error', 'Unknown error')}")
            print(f"Initial Balance: {initial_balance}")

def main():
    # Configuration
    API_KEY = "your_api_key_here"  # Replace with your actual Grass API key
    PROXY_ADDRESS = "your_proxy_address"  # Replace with your proxy address
    PROXY_PORT = 8080  # Replace with your proxy port
    
    # Farming parameters
    TRAFFIC_SOURCE = "organic"  # Example source
    TRAFFIC_VOLUME = 1000  # Example volume
    TRAFFIC_DURATION = 300  # 5 minutes in seconds
    
    # Initialize and run bot
    bot = GrassBot(API_KEY, PROXY_ADDRESS, PROXY_PORT)
    bot.run(TRAFFIC_SOURCE, TRAFFIC_VOLUME, TRAFFIC_DURATION)

if __name__ == "__main__":
    main()