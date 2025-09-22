import socket
import re
import random

HOST = "127.0.0.1"
PORT = 4200

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen(5)

def gen_answer():
    nums = []
    while len(nums) < 4:
        newnum = random.randint(0, 9)
        if newnum in nums:
            continue
        else:
            nums.append(newnum)
    return "".join(str(num) for num in nums)

def guess_judge(guess, answer):
    a = 0
    b = 0
    guess = list(guess)
    answer = list(answer)
    for i in range(0, 4):
        if guess[i] == answer[i]:
            a += 1
        elif guess[i] in answer:
            b += 1
    return str(a) + "A" + str(b) + "B"

answer = gen_answer()
print("first answer: ", answer)
print("guess|answer")
tryTime = 1

conn, addr = server.accept()

while True:
    guess = conn.recv(1024).decode()
    print(guess, "|", answer)
    if len(guess) != 4:
        if guess.lower() == 'q':
            break
        errorMessage = "(Press q to exit)Your guess must be different four numbers!\nTry again: "
        conn.sendall(errorMessage.encode())
    elif re.match(r"\d{4}", guess) is not None:
        if guess == answer:
            message = (
                "Well done! total try: "
                + str(tryTime)
                + " times\n(Press q to exit)The answer has been changed make your guess: "
            )
            conn.sendall(message.encode())
            answer = gen_answer()
            tryTime = 1
            print("new answer: ", answer)
            print("guess|answer")
        elif not all(guess.count(num) == 1 for num in guess):
            message = "(Press q to exit) Your guess must be four different numbers!\nTry again: "
            conn.sendall(message.encode())
        else:
            message = (
                guess_judge(guess, answer)
                + "\n(Press q to exit) Quite close! make another guess: "
            )
            conn.sendall(message.encode())
    else:
        errorMessage = "(Press q to exit) Your guess must be four different numbers!\nTry again: "
        conn.sendall(errorMessage.encode())
    tryTime += 1

conn.close()
server.close()
