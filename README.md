# reading_files_recursively_C
Reading files under specific paths recursively

Let's take for consideration our example file:
```
tire.txt
event.txt
meat.txt
salt.txt
read.txt
would.txt
each.txt
then.txt
bed.txt
```
Our program should read content from an example file and then read recursively content from every file path at the next lines.
As we don't have files from path tire.txt, event.txt, and so on, the program will only read the content of the example file. 
Additionally, 1 will be printed at the end of program execution as only 1 file was read.
