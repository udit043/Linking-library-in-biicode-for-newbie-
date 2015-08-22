If you are new to biicode and creating your project and it need library(or object) files to link then follow these steps..
In this program i will show you how to link object(.obj) file , linking library(.lib) or object(.obj) file is almost same
Start new project :
      C:\Biicode\Program>bii init 24aug -L
This will create a project folder inside (C:\Biicode\Program)
Now ,
      C:\Biicode\Program>cd 24aug
      C:\Biicode\Program\24aug>
Now type,
      C:\Biicode\Program\24aug>echo "//code goes here">>main.c
This will create a .c file inside 24aug folder
Now open .c file using any text editor and copy this code

#include "stdio.h"
#include "conio.h"
int main()
{
//This program need object (.obj) file to link
printf("Hello World (black-n-white)\n");
textcolor(10); // this function will only be run if .obj file is successfully linked or it will give error : undefined reference to 'textcolor'
printf("Hello world (color)");
return 0;
}

Save this code.
Now run this code by typing
      C:\Biicode\Program\24aug>bii build
It will give error : undefined reference to 'textcolor'

****************** LINKING LIBRARY/OBJECT file ******************

Create a new block named lib by typing
      C:\Biicode\Program\24aug>bii new block/lib
This will create a folder (C:\Biicode\Program\24aug\blocks\block\lib)
Now copy conio.o (you can copy other .lib/.o files which needs to link) and paste them inside lib folder

Now open CMakeList.txt file located inside (C:\Biicode\Program\24aug) folder and after ADD_BII_TARGETS() add this line 
TARGET_LINK_LIBRARIES(${BII_BLOCK_TARGET} INTERFACE C:/Biicode/Program/24aug/blocks/block/lib/conio.o)

Now run the code by typing 
      C:\Biicode\Program\24aug>bii build
This time program will compile fine without any linker error and you will see executable file inside bin folder.

In this way you can link more than two library/object file easily.
