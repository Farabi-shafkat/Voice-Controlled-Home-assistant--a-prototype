from communicate import communicate
from speech_to_text import speech_to_text
import os


if __name__ == "__main__":
    sp=speech_to_text()
    with open('IP_address.txt', 'r') as file:
        IP = file.read().replace('\n', '')
        
    if  os.system('ping -n 1 -w 1 '+IP+'>nul')!=0:
        
        print("finding IP, this may take a while....")
        IP="192.168.137."
          #  ping.verbose_ping('www.google.com', count=1)
        for last in range(256):
            if last==1:
                continue
            ping = os.system('ping -n 1 -w 1 192.168.137.'+str(last)+">nul")
            if ping == 0:
                IP=IP+str(last)
                break;
        with open('IP_address.txt', 'w') as file:
            file.write(IP)     





    print("IP FOUND   ",IP)
    
    
    com=communicate(IP,80,"")
    com.set_cmd("status")
    com.send()

    #IP_addr='192.186.137'dssadasd
    #for last in range(256):
     #   com=communicate('192.168.137.'+str(last),80,"")
  #  com=communicate('',80,"")
    while 1:

        print("press S and speak....Or press T and type in the command:")
        inp=input()
        
        if inp=='S':
            cmd=sp.do_stuff()
            
            print(cmd)
            com.set_cmd(cmd)
            com.send()
        elif inp=='T':
            print('Type in any one command:    format: light <number> <off/on>')
            cmd=input()
            print(cmd)
            com.set_cmd(cmd)
            com.send()
        #print("5 sec stop")                                                                                                                                                                      
        #time.sleep(5)
        #print("woken")
        #com.set_cmd("turn light off")
        #com.send()

       