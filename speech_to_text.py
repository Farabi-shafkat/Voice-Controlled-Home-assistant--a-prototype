import speech_recognition as sr
import os
#os.chdir('F:\\personal project\\speech recognition')
#print(sr.__version__)
r=sr.Recognizer()
print(sr.Microphone.list_microphone_names())
mic=sr.Microphone()

class speech_to_text:
    def record_sound(self):
        with mic as source:
            # r.adjust_for_ambient_noise(source)
            r.adjust_for_ambient_noise(source)
            print("speak_now")
            audio1=r.listen(source)
            #audio2=r.record(source,duration=4)
       # text1="did not work"
        return audio1
    def extract_string(self,audio1):
        try:
            text1=r.recognize_google(audio1, show_all=True)
            text1=self.refine(text1)
            return text1
        except sr.RequestError:
            print("API Unavailable")
        except sr.UnknownValueError:
            print("Unable to recognize speech\nplease try again")
            return "error"
    def do_stuff(self):
        cmd="error"
        while cmd=="error":
             obj=self.record_sound()
             cmd=self.extract_string(obj)
        
        return cmd             


    def refine(self,text_list):
        print(text_list)
        text_list=text_list['alternative']
        for tx1 in text_list:
            zero1='light zero on'
            zero0='light zero off'
            one0='light one off'
            one1='light one on'
            two1='light two on'
            two0='light two off'
            three0='light three off'
            three1='light three on'
            four0='light four off'
            four1='light four on'

            tx=tx1['transcript']
            print(tx)
            if(tx=='light zero on'):
                return zero1
            elif(tx=='light zero off'):
                return zero0
            elif(tx=='light one on'):
                return one1
            elif(tx=='light one off'):
                return one0
            elif(tx=='light two on'):
                return two1
            elif(tx=='light two off'):
                return two0 
            elif(tx=='light three on'):
                return three1
          
            elif(tx=='light three off'):
                return three0
            elif(tx=='light four on'):
                return four1
            elif(tx=='light four off'):
                return four0



            elif(tx=='light zero on'):
                return zero1
            elif(tx=='light zero of'):
                return zero0
            elif(tx=='light one on'):
                return one1
            elif(tx=='light one of'):
                return one0
            elif(tx=='light two on'):
                return two1
            elif(tx=='light two of'):
                return two0 
            elif(tx=='light three on'):
                return three1

            elif(tx=='light three of'):
                return three0
            elif(tx=='light four on'):
                return four1
            elif(tx=='light four of'):
                return four0


            elif(tx=='light for on'):
                return four1
            elif(tx=='light for off'):
                return four0
            elif(tx=='light for of'):
                return four0

            elif(tx=='light 0 on'):
                    return zero1
            elif(tx=='light 0 off'):
                return zero0
            elif(tx=='light 1 on'):
                return one1
            elif(tx=='light 1 off'):
                return one0
            elif(tx=='light 2 on'):
                return two1
            elif(tx=='light 2 off'):
                return two0 
            elif(tx=='light 3 on'):
                return three1
          
            elif(tx=='light 3 off'):
                return three0
            elif(tx=='light 4 on'):
                return four1
            elif(tx=='light 4 off'):
                return four0

           



if __name__ == "__main__":
    test=speech_to_text()
    print(test.do_stuff())

#text2=r.recognize_google(audio2)
#print(text1)
#print(text2)