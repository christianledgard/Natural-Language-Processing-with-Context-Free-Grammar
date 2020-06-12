from tkinter import *

#lee la gramatica-----------------------------------------------------------    
def read_CFG():
    CFG={}
    derivation=[]
    text = input_text.get("1.0",END)
    rules = text.split("\n")[:-1]
    #print(rules)
    for line in rules:
        rule= line.split("->")
        #print(rule)
        CFG[rule[0]]=rule[1]

    
    for rule in CFG:
        derivation=CFG[rule].split("|")
        for i in range(len(derivation)):
            derivation[i]=derivation[i].split(",")

        CFG[rule]=derivation

    print(CFG)
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
