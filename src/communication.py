


import urllib.request, json, time
from sys import argv, exit
#usage :
#  python3 communication.py get_pool
#  python3 communication.py post

# Errors
# -1 invalid sintaxe
# -2 offline

def error():
    print("invalid usage")
    exit(-1)

def offline():
    print("offline")
    exit(-2)

url = "http://127.0.0.1"
arq = "mining_pool_info_file.txt"

def get_mining_pool_info():
    try:
        req = urllib.request.urlopen(url).read()
    except urllib.error.URLError:
        offline()
    
    
    List = json.loads(req)

    with open(arq, 'w') as f:
        f.write(str(List[0]) + "\n")
        f.write(str(List[1]))
    
    exit(0)


def post():
    pass

if __name__ == "__main__":
    if(len(argv) < 2):
        error()

    if(argv[1] == "get_pool"):
        get_mining_pool_info()
    
    elif(argv[1] == "post"):
        post()

    else:
        error()
