import tkinter as tk
import random
root = tk.Tk()
root.title("Unique Password Generator")
def generate():
    passw_label.config(text=passgen())

def passgen():
    
    qqq = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
    pass_len = int(passw_var.get())
    password = ""
    for i in range(0,pass_len):
        random_char = random.choice(qqq)
        password = password + random_char
    return password
    

passw_var=tk.StringVar()
length_label = tk.Label(root, text = 'Password Length : ', font=('calibre',10, 'bold'))
length_entry=tk.Entry(root, textvariable = passw_var, font = ('calibre',10,'normal'))
generate_btn=tk.Button(root,text = 'Generate', command = generate)
passw_label = tk.Label(root, text = '')

length_label.pack(fill = 'both', expand = True,padx = 10, pady = 10)
length_entry.pack(fill = 'both', expand = True,padx = 10, pady = 10)
generate_btn.pack(fill = 'both', expand = True,padx = 10, pady = 10)
passw_label.pack(fill = 'both', expand = True,padx = 10, pady = 10)
root.mainloop()

