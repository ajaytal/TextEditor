# TextEditor

C++ text editor that takes in a file as its only command line argument. 
	The max number of lines in the file is 30 lines, and each line can be up to 40 characters long. If any one of these two conditions aren't met, the program will prompt an error message and terminate. The program prompts the user for a command until the user enters 'q' to quit. The user can type save <filename> to save the current contents of the file to the new specified file. If the user enters 'q' and hasn't saved the file, then the editor will ask the user if they want to quit without saving. The controls to move the cursor are WASD. (up, left, down, and right respectively.) The user can enter an integer after a WASD control to move the cursor an integer amount of spaces. The window of the editor only displays 10 lines. The editor allows for scrolling of the window when needed, and allows for moving the cursor horiontally. The user can simply press enter when prompted to repeat the previous command. If the user enters 'i' followed by a string, the text editor will insert the string starting at the current cursor position. The inserted string will carry onto the next line if needed. The user can delete a whole line by typing only 'del', and can delete a certain amount of characters only if the deletion does not go into the next line by typing 'del' followed by an integer. The user can also undo an insertion or deletion by typing 'u', or redo an undo operation by typing 'r'. Lastly, if the user makes a bunch of modifications and undos all of them, the user can quit the program without saving and will not be promped by "Are you sure you want to quit?"
