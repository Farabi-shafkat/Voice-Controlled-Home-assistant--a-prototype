import socket
import time

class communicate:
    sock=None
    port=None
    IP=None
    port=None
    state=None
    cmd=None
    def __init__(self,IP_val,port_val,command):
        self.sock=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.IP=IP_val
        self.port=port_val
        self.sock.connect((self.IP,self.port))
        print("connection established") 
        self.state={'led0':'off','led1':'off','led2':'off','led3':'off','led4':'off'}
        self.cmd=command
    def set_cmd(self,command):
        self.cmd=command
    def see_state(self):
        return self.state
    def send(self):
        print("sending command ",self.cmd)
        
        retry=5

        if self.cmd=="light zero on":
            while self.state['led0']!='on' and retry>=0 : 
                print("turning on LED 0")
                self.cmd="?on0EE"
                self.sock.send(self.cmd.encode("utf8"))
                data=""
                print("sent")
                while data!="ON0":
                    print(data)
                    data=self.sock.recv(3)
                    data=data.decode("ascii")
                    print(data)
                print("light 0 turned on")
                self.state['led0']="on"
                retry-=1
      
        
        elif self.cmd=="light zero off":
            while self.state['led0']!='off' and retry>=0 :
                print("turning off LED 0")
                self.cmd="?of0EE"
                self.sock.send(self.cmd.encode("utf8"))
                data=""
                while data!="OFF0":
                    data=self.sock.recv(4)
                    data=data.decode("ascii")
                    print(data)
                print("light 0 turned off")
                self.state['led0']="off"
                retry-=1




        elif self.cmd=="light one on":
            while self.state['led1']!='on' and retry>=0 :
                print("turning on LED 1")
                self.cmd="?on1EE"
                self.sock.send(self.cmd.encode("utf8"))
                data=""
                print("sent")
                while data!="ON1":
                    print(data)
                    data=self.sock.recv(3)
                    data=data.decode("ascii")
                    print(data)
                print("light 1 turned on")
                self.state['led1']="on"
                retry-=1
      
        
        elif self.cmd=="light one off":
            while self.state['led1']!='off' and retry>=0 :
                print("turning off LED 1")
                self.cmd="?of1EE"
                self.sock.send(self.cmd.encode("utf8"))
                data=""
                while data!="OFF1":
                    data=self.sock.recv(4)
                    data=data.decode("ascii")
                    print(data)
                print("light 1 turned off")
                self.state['led1']="off"
                retry-=1
        
        
        elif self.cmd=="light two on":
            while self.state['led2']!='on' and retry>=0 :
                print("turning on LED 2")
                self.cmd="?on2EE"
                self.sock.send(self.cmd.encode("utf8"))
                data=""
                print("sent")
                while data!="ON2":
                    print(data)
                    data=self.sock.recv(3)
                    data=data.decode("ascii")
                    print(data)
                print("light 2 turned on")
                self.state['led2']="on"
                retry-=1
      
        
        elif self.cmd=="light two off":
            while self.state['led2']!='off' and retry>=0 :
                print("turning off LED 2")
                self.cmd="?of2EE"
                self.sock.send(self.cmd.encode("utf8"))
                data=""
                while data!="OFF2":
                    data=self.sock.recv(4)
                    data=data.decode("ascii")
                    print(data)
                print("light 2 turned off")
                self.state['led2']="off"
                retry-=1

        elif self.cmd=="light three on":
            while self.state['led3']!='on' and retry>=0 :
                print("turning on LED 3")
                self.cmd="?on3EE"
                self.sock.send(self.cmd.encode("utf8"))
                data=""
                print("sent")
                while data!="ON3":
                    print(data)
                    data=self.sock.recv(3)
                    data=data.decode("ascii")
                    print(data)
                print("light 3 turned on")
                self.state['led3']="on"
                retry-=1
      
        
        elif self.cmd=="light three off":
            while self.state['led3']!='off' and retry>=0 :
                print("turning off LED 3")
                self.cmd="?of3EE"
                self.sock.send(self.cmd.encode("utf8"))
                data=""
                while data!="OFF3":
                    data=self.sock.recv(4)
                    data=data.decode("ascii")
                    print(data)
                print("light 3 turned off")
                self.state['led3']="off"
                retry-=1  

        elif self.cmd=="light four on":
            while self.state['led4']!='on' and retry>=0 :
                print("turning on LED 4")
                self.cmd="?on4EE"
                self.sock.send(self.cmd.encode("utf8"))
                data=""
                print("sent")
                while data!="ON4":
                    print(data)
                    data=self.sock.recv(3)
                    data=data.decode("ascii")
                    print(data)
                print("light 4 turned on")
                self.state['led4']="on"
                retry-=1
      
        
        elif self.cmd=="light four off":
            while self.state['led4']!='off' and retry>=0 :
                print("turning off LED 4")
                self.cmd="?of4EE"
                self.sock.send(self.cmd.encode("utf8"))
                data=""
                while data!="OFF4":
                    data=self.sock.recv(4)
                    data=data.decode("ascii")
                    print(data)
                print("light 4 turned off")
                self.state['led4']="off"
                retry-=1        


        elif self.cmd=="status":
             while retry>=0 :
                print("fetching status")
                self.cmd="?staEE"
                self.sock.send(self.cmd.encode("utf8"))
                data=""
                while data=="":
                    data=self.sock.recv(10)
                    data=data.decode("ascii")
                    print(data)
                print("status : ",data)
                for i in range(5):
                    #print(data[i+i],data[i+i+1], "eije")
                    if data[i+i]=='4' and data[i+i+1]=='8':
                        self.state['led'+str(i)]='off'
                    elif data[i+i]=='4' and data[i+i+1]=='9':
                        self.state['led'+str(i)]='on' 
                retry=-1  
        
     

        elif self.cmd=="all light on":
            print("here")
           
            print("turning on all LED")
            self.cmd="?al1EE"
            self.sock.send(self.cmd.encode("utf8"))
            data=""
            while data!="ONA":
                data=self.sock.recv(3)
                data=data.decode("ascii")
                print(data)
            print("all lights turned on")
            self.state['led0']="on"
            self.state['led1']="on"
            self.state['led2']="on"
            self.state['led3']="on"
            self.state['led4']="on"
            
        elif self.cmd=="all light off":
           
            print("turning off all LED")
            self.cmd="?al0EE"
            self.sock.send(self.cmd.encode("utf8"))
            data=""
            while data!="OFFA":
                data=self.sock.recv(4)
                data=data.decode("ascii")
                print(data)
            print("all lights turned off")
            self.state['led0']="off"
            self.state['led1']="off"
            self.state['led2']="off"
            self.state['led3']="off"
            self.state['led4']="off"
           
        return

if __name__ == "__main__":
    com=communicate('192.168.137.169',80,"light zero on")
    com.send()
    print("5 sec stop")
    time.sleep(5)
    print("woken")
    com.set_cmd("light zero off")
    com.send()


    print("woken")
    com.set_cmd("light one on")   
    com.send()
    time.sleep(5)
    print("woken")
    com.set_cmd("light one off")
    com.send()
    time.sleep(5)

    print("woken")
    com.set_cmd("light two on")   
    com.send()
    time.sleep(5)
    print("woken")
    com.set_cmd("light two off")
    com.send()
    time.sleep(5)
    

    print("woken")
    com.set_cmd("light three on")   
    com.send()
    time.sleep(5)
    print("woken")
    com.set_cmd("light three off")
    com.send()
    time.sleep(5)


    print("woken")
    com.set_cmd("light four on")   
    com.send()
    time.sleep(5)
    print("woken")
    com.set_cmd("light four off")
    com.send()
    time.sleep(5)