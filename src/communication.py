import urllib.request, json, time, urllib3
from sys import argv, exit
#usage :
#  python3 communication.py get_pool
#  python3 communication.py post

# Errors
# -1 invalid sintaxe
# -2 offline

# Invalid usage
def error():
    exit(-1)

# Offline server or computer
def offline():
    exit(-2)

url = 'http://127.0.0.1'
arq = 'mining_pool_info_file.txt'

def get_mining_pool_info():
    try:
        req = urllib.request.urlopen(url).read()
    except urllib.error.URLError:
        offline()
    except:
        offline()
    
    req = str(req)
    req = req.replace("b'", '').replace("'", "")
    print(req)
    List = json.loads(str(req))

    with open(arq, 'w') as f:
        f.write(str(List[0]) + '\n')
        f.write(str(List[1]))
    
    exit(0)


# send msg to server
def post(msg):
    encoded_body = msg 

    http = urllib3.PoolManager()
    try:
        r = http.request('POST', url,
                        headers={'Content-Type': 'text/html'},
                        body=encoded_body)
        returned_data = str(r.data)
    except:
        print("Erro no POST")

if __name__ == '__main__':
    if(len(argv) < 2):
        error()

    if(argv[1] == 'get_pool'):
        get_mining_pool_info()
    
    elif(argv[1] == 'post'):
        if(len(argv) > 2):
            post(argv[2])
        else:
            error()

    else:
        error()
