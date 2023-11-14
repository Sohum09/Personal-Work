import tkinter as tk
from tkinter import filedialog

def open_file():
    file_path = filedialog.askopenfilename(initialdir="/", title="Select A File", filetypes=[("Text files", "*.txt"), ("All files", "*.*")])
    
    # Extract the file name from the full path
    file_name = file_path.split("/")[-1]  # Change the separator based on your operating system

    # You can now use the file_name as needed, for example, display it in a label
    label.config(text=f"Selected File: {file_name}")

# Create the main Tkinter window
root = tk.Tk()
root.title("File Selection Example")

# Create a button to open the file dialog
button = tk.Button(root, text="Open File", command=open_file)
button.pack(pady=20)

# Create a label to display the selected file name
label = tk.Label(root, text="Selected File: None")
label.pack()

# Run the Tkinter event loop
root.mainloop()
