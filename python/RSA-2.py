def mod_pow(base, exp, mod):
    """快速模冪計算：返回 (base^exp) % mod"""
    result = 1
    base = base % mod
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result

# 參數
n = 15811
e = 257
ciphertexts = [15369, 1, 9511, 11485, 4379, 10397]

# 建立密文到明文的映射
cipher_to_plain = {}
for m in range(1, 27):  # 對應 a=1 到 z=26
    c = mod_pow(m, e, n)  # 計算 c = m^e mod n
    cipher_to_plain[c] = chr(96 + m)  # 將 m 轉為字母 (1->a, 2->b, ..., 26->z)

# 解密
message = ''
for c in ciphertexts:
    if c in cipher_to_plain:
        message += cipher_to_plain[c]
    else:
        message += '?'  # 若密文無對應，標記為未知

print("解密的訊息:", message)