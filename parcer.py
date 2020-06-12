from tkinter import *
import json

file_name="gramaticas.txt"
CFG={}

#lee la gramatica-----------------------------------------------------------    
def read_CFG():
    derivation=[]
    text = input_text.get("1.0",END)
    rules = text.split("\n")[:-1]
    print(rules)
    for line in rules:
        rule= line.split("->")
        print(rule)
        CFG[rule[0]]=rule[1]

    
    for rule in CFG:
        print(rule)
        derivation=CFG[rule].split("|")
        for i in range(len(derivation)):
            derivation[i]=derivation[i].split(",")

        CFG[rule]=derivation

    print(CFG)
    gramaticas = open(file_name,"a")
    gramaticas.write(json.dumps(CFG))
    gramaticas.write("\n")
    gramaticas.close()


#-----------------------------------------------------------------    

#abre la ventana--------------------------------------------------------    
window = Tk()
window.title('Parser')

input_text= Text(window,height=20,width=60)
input_text.focus()
input_text.grid(row=0,column=0)

parse_button= Button(window,text="Parse", command=read_CFG)
parse_button.grid(row=0,column=1)



mainloop()
#-----------------------------------------------------------------    
