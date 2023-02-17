word={"HELLO":"ENGLISH","HOLA":"SPANISH","HALLO":"GERMAN","BONJOUR":"FRENCH","CIAO":"ITALIAN","ZDRAVSTVUJTE":"RUSSIAN"}
counter=1
while 1:
    try:
        x=input()
        if x=='#':
            break
        if x in word.keys():
            print("Case ",counter,": ",word[x],sep='')
        else:
            print("Case ",counter,": UNKNOWN",sep='')
        counter+=1
    except:
        break