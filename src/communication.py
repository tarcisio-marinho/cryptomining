


import urllib.request, json, time
from sys import argv, exit

# Errors
# -1 invalid sintaxe
# -2 offline

def error():
    print("invalid usage")
    exit(-1)

def offline():
    print("offline")
    exit(-2)

# url = "http://127.0.0.1"
url = "https://google.com.br"


def get_mining_pool_info():
    try:
        req = urllib.request.urlopen(url).read()
    except urllib.error.URLError:
        offline()
        

    print(req)


if __name__ == "__main__":
    if(len(argv) < 2):
        error()

    if(argv[1] == "get_pool"):
        get_mining_pool_info()
    
    elif(argv[1] == "post"):
        pass

    else:
        error()
