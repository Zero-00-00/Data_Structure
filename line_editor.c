//made by Praloy
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <conio.h>

void newLine();
void addWord(char*);
void write();
void reset_word();
void func();
void read();
void cp(int, int, int, int, int);
void cpypst(int, int, int, int, int);
void insert(int, int, char*);
void replace(int, int, char*);
void delete(int, int, char*);
void save_to_file(const char*);
void saveas_utf8(const char*);
void close();

typedef struct Word
{
    char w[50];
    struct Word* next;
}word;

typedef struct Line
{
    struct Word* next;
    struct Line* l_nxt;
}line;

line* l_head = NULL;
word* w_head = NULL;

void newLine()
{
    line *t1, *t2 = l_head;
    
    if (w_head == NULL) {
        printf("No words to add to a new line.\n");
        return;
    }

    t1=(line*)malloc(sizeof(line));
    t1->next=w_head;
    t1->l_nxt=NULL;

    if (l_head == NULL)
    {  
        l_head=t1;
    }
    else
    {
        while(t2->l_nxt!=NULL)
        {
            t2=t2->l_nxt;
        }
        t2->l_nxt=t1;
    }
    //("New line added.\n");
    reset_word();
}

void addWord(char* str)
{
    word *t1, *t2 = w_head;

    t1=(word*)malloc(sizeof(word));
    strcpy(t1->w, str);
    t1->next=NULL;

    if (w_head == NULL)
    {  
        w_head=t1;
    }
    else
    {
        while(t2->next!=NULL)
        {
            t2=t2->next;
        }
        t2->next=t1;
    }
    //printf("Added word: %s", t1->w);
}

void write()
{
    char input;
    char str[50];  
    int i = 0;     //to keep track of position in str
    word* t = w_head;

    while (1) 
    {
        input = _getch();       // Read a character from the input
        printf("%c", input);   //print the input data to console

        switch (input)
        {
            case ' ':
            str[i] = '\0';  // Null-terminate the string
            addWord(str);
            i=0;
            break;
            
            case '\n':
            str[i] = '\0';  // Null-terminate the string
            addWord(str);   // Add the word to the list
            newLine();      // Add the word list to the line
            printf("\n");   // Print a newline to console for readability
            printf("    ");
            i = 0;          // Reset the index for the next word
            break;

            case '`':
            str[i] = '\0';  // Null-terminate the string
            i=0;
            func();
            break;

            case '\r':  // Enter key is detected as '\r' in Windows
            str[i] = '\0';  // Null-terminate the string
            addWord(str);   // Add the word to the list
            newLine();      // Add the word list to the line
            printf("\n");   // Print a newline to console for readability
            printf("    ");
            i = 0;          // Reset the index for the next word
            break;

            default:
            str[i] = input;  // Add the character to the string
            i++;  // Increment the index
            break;
        }
    }
}

void reset_word()
{
    w_head = NULL;
}

void func()         //functions when utility key '`' is pressed
{
    int ch;
    int a, b, cnt, c, d;
    char str[50] = {0};
    char default_location[100] = "C:/Users/pralo/OneDrive/Desktop/";  // Default location
    char user_input[100];
    char name[20];

    printf("\n1.Read\n2.Cut and Paste\n3.Copy and Paste\n4.Insert\n5.Replace\n6.Delete\n7.Save to file\n8.Save As with UTF-8 encoding\n9.Close Program\nEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1:
        printf("\n");
        read();
        break;
        case 2:
        printf("Enter the position to cut from: ");
        scanf("%d %d", &a, &b);
        printf("Enter the Number of Words you want to Cut: ");
        scanf("%d", &cnt);
        printf("Enter the position to paste to: ");
        scanf("%d %d", &c, &d);
        cp(a, b, cnt, c, d);
        break;
        case 3:
        printf("Enter the position to copy from: ");
        scanf("%d %d", &a, &b);
        printf("Enter the Number of Words you want to Copy: ");
        scanf("%d", &cnt);
        printf("Enter the position to paste to: ");
        scanf("%d %d", &c, &d);
        cpypst(a, b, cnt, c, d);
        break;
        case 4:
        printf("Enter the position to insert to: ");
        scanf("%d %d", &a, &b);
        printf("Enter the Word to insert: ");
        scanf("%s", str);
        insert(a, b, str);
        break;
        case 5:
        printf("Enter the position to Replace Word: ");
        scanf("%d %d", &a, &b);
        printf("Enter the New Word: ");
        scanf("%s", str);
        replace(a, b, str);
        break;
        case 6:
        printf("Enter the position to delete from: ");
        scanf("%d %d", &a, &b);
        delete(a, b, str);
        break;
        case 7:
        printf("Default file location: %s\n", default_location);
        printf("Press 1 to change the file location: ");
        scanf("%s", user_input);
        if (user_input[0] == 1) 
        {
            printf("Enter the new file path and name: ");
            scanf("%s", default_location);
        }
        printf("Enter the name of your file (name.txt): ");
        scanf("%s", name);
        // Ensure there is a trailing slash before appending the filename
        if (default_location[strlen(default_location) - 1] != '/' &&
            default_location[strlen(default_location) - 1] != '\\') 
        {
            strcat(default_location, "/");
        }
        //concat the name with location
        strcat(default_location, name);
        //save
        save_to_file(default_location);
        break;
        case 8:
        printf("Default file location: %s\n", default_location);
        printf("Press 1 to change the file location: ");
        scanf("%s", user_input);
        if (user_input[0] == '1') 
        {
            printf("Enter the new file path: ");
            scanf("%s", default_location);
        }
        printf("Enter the name of your file (name.txt): ");
        scanf("%s", name);
        // Ensure there is a trailing slash before appending the filename
        if (default_location[strlen(default_location) - 1] != '/' &&
            default_location[strlen(default_location) - 1] != '\\') 
        {
            strcat(default_location, "/");
        }
        // Concatenate the name with location
        strcat(default_location, name);
        // Save as UTF-8
        saveas_utf8(default_location);
        break;
        case 9:
        close();
        break;
        default:
        printf("Invalid Choice\n");
    }
    printf("\n--> ");
}

void read()
{
    line* l_temp = l_head;
    if (l_temp == NULL) {
        printf("No data to read\n");
        return;
    }

    while(l_temp != NULL)
    {
        word* w_temp = l_temp->next;
        while(w_temp != NULL)
        {
            printf("%s ", w_temp->w);
            w_temp = w_temp->next;
        }
        printf("\n");
        l_temp = l_temp->l_nxt;
    }
}

//cut-paste operation
void cp(int c_line, int c_word, int count, int p_line, int p_word)            
{
    char cpyw[50] = {0};          //here the word will be saved

    //no of lines
    line* tl = l_head;
    int l_len = 0;
    while(tl!=NULL)                                           
    {
        tl=tl->l_nxt;
        l_len++;
    }
    
    //cut operation
    line* lc_pt = l_head;
    if (c_line>l_len || c_line<1)           //validation
    {
        printf("Invalid Position\n");
        return;
    }
    //take the line pointer to the line to cut from
    for (int i = 0; i < c_line - 1; i++)                          
    {
        lc_pt = lc_pt->l_nxt;
    }
    //get the len of the line
    word* wt = lc_pt->next;
    int c_len = 0;
    while(wt!=NULL)                                           
    {
        wt=wt->next;
        c_len++;
    }
    
    if (c_word+count-1>c_len || c_word<1)       //validation
    {
        printf("Invalid Position\n");
        return;
    }

    //retrive word and delete
    for(int i=0; i<count; i++)
    {
        word* t1=lc_pt->next;
        word* t2=t1->next;
        if (t1->next==NULL)
        {
            lc_pt->next=NULL;
            strcpy(cpyw, t1->w);
            free(t1);
        }
        else if (c_word==1)
        {
            lc_pt->next=t2;
            strcpy(cpyw, t1->w);
            free(t1);
        }
        else
        {
            int i=1;
            while(i!=c_word-1)
            {
                t1=t1->next;
                t2=t1->next;
                i++;
            }
            t1->next=t2->next;
            strcpy(cpyw, t2->w);
            //printf("\n%d\n%s\n%s", i, cpyw, t2->w);
            free(t2);
        }

        //paste operation
        //take the line pointer to the line to paste
        line *lp_pt = l_head;
        if (p_line>l_len || p_line<1)
        {
            printf("Invalid Position\n");
            return;
        }    
        else
        {
            for (int i = 0; i < p_line - 1; i++)                          
            {
                lp_pt = lp_pt->l_nxt;
            }
        }
        //get the len of the line
        wt = lp_pt->next;
        int p_len = 0;
        while(wt!=NULL)                                           
        {
            wt=wt->next;
            p_len++;
        }
        //insert the word at position
        if (p_word>p_len+1 || p_word<1)
        {
            printf("Invalid Position\n");
            return;
        }   
        else
        {
            word *t1, *t2;
            int i=1;
            t1=(word*)malloc(sizeof(word));
            strcpy(t1->w, cpyw);
            t1->next=NULL;
            t2=lp_pt->next;
            if (p_word == 1)
            {
                t1->next=t2;
                lp_pt->next=t1;
            }
            while(i!=p_word-1)
            {
                t2=t2->next;
                i++;
            }
            t1->next=t2->next;
            t2->next=t1;
            //printf("\n%d\n%s\n%s", i, cpyw, t1->w);
        }

        p_word++;           //no need to increment c_word as after cut same position
    }
}

//copy-paste operation
void cpypst(int c_line, int c_word, int count, int p_line, int p_word)            
{
    char cpyw[50] = {0};          //here the word will be saved

    //no of lines
    line* tl = l_head;
    int l_len = 0;
    while(tl!=NULL)                                           
    {
        tl=tl->l_nxt;
        l_len++;
    }
    
    //cut operation
    line* lc_pt = l_head;    
    if (c_line>l_len || c_line<1)       //validation
    {
        printf("Invalid Position\n");
        return;
    }
    //take the line pointer to the line to cut from
    for (int i = 0; i < c_line - 1; i++)                          
    {
        lc_pt = lc_pt->l_nxt;
    }
    //get the len of the line
    word* wt = lc_pt->next;
    int c_len = 0;
    while(wt!=NULL)                                           
    {
        wt=wt->next;
        c_len++;
    }

    if (c_word+count-1>c_len || c_word<1)       //validation
    {
        printf("Invalid Position\n");
        return;
    }
    //retrive word
    for (int i=0; i<count; i++)
    {
        word* t1=lc_pt->next;
        int i=1;
        while(i!=c_word)
        {
            t1=t1->next;
            i++;
        }
        strcpy(cpyw, t1->w);

        //paste operation
        //take the line pointer to the line to cut from
        line *lp_pt = l_head;
        if (p_line>l_len || p_line<1)
        {
            printf("Invalid Position\n");
            return;
        }    
        else
        {
            for (int i = 0; i < p_line - 1; i++)                          
            {
                lp_pt = lp_pt->l_nxt;
            }
        }
        //get the len of the line
        wt = lp_pt->next;
        int p_len = 0;
        while(wt!=NULL)                                           
        {
            wt=wt->next;
            p_len++;
        }
        //insert the word at position
        if (p_word>p_len+1 || p_word<1)
        {
            printf("Invalid Position\n");
            return;
        }   
        else
        {
            word *t1, *t2;
            int i=1;
            t1=(word*)malloc(sizeof(word));
            strcpy(t1->w, cpyw);
            t1->next=NULL;
            t2=lp_pt->next;
            if (p_word == 1)
            {
                t1->next=t2;
                lp_pt->next=t1;
            }
            while(i!=p_word-1)
            {
                t2=t2->next;
                i++;
            }
            t1->next=t2->next;
            t2->next=t1;
        }

        c_word++;
        p_word++;
    }
}

void insert(int ln, int wrd, char* str)
{
    //no of lines
    line* tl = l_head;
    int l_len = 0;
    while(tl!=NULL)                                           
    {
        tl=tl->l_nxt;
        l_len++;
    }
    //take the line pointer to the line to insert to
    line* l_pt = l_head;
    if (ln>l_len || ln<1)
    {
        printf("Invalid Position\n");
        return;
    }
    else
    {
        for (int i = 0; i < ln - 1; i++)                          
        {
            l_pt = l_pt->l_nxt;
        }
    }
    //get the len of the line
    word* wt = l_pt->next;
    int c_len = 0;
    while(wt!=NULL)                                           
    {
        wt=wt->next;
        c_len++;
    }
    //insert the word at position
    if (wrd>c_len+1 || wrd<1)
    {
        printf("Invalid Position\n");
        return;
    }   
    else
    {
        word *t1, *t2;
        int i=1;
        t1=(word*)malloc(sizeof(word));
        strcpy(t1->w, str);
        t1->next=NULL;
        t2=l_pt->next;
        if (wrd == 1)
        {
            t1->next=t2;
            l_pt->next=t1;
        }
        while(i!=wrd-1)
        {
            t2=t2->next;
            i++;
        }
        t1->next=t2->next;
        t2->next=t1;
    }
}

void replace(int ln, int wrd, char* str)
{
    //no of lines
    line* tl = l_head;
    int l_len = 0;
    while(tl!=NULL)                                           
    {
        tl=tl->l_nxt;
        l_len++;
    }
    //take the line pointer to the line to insert to
    line* l_pt = l_head;
    if (ln>l_len || ln<1)
    {
        printf("Invalid Position\n");
        return;
    }
    else
    {
        for (int i = 0; i < ln - 1; i++)                          
        {
            l_pt = l_pt->l_nxt;
        }
    }
    //printf("%d\n", l_pt);
    //get the len of the line
    word* wt = l_pt->next;
    int c_len = 0;
    while(wt!=NULL)                                           
    {
        wt=wt->next;
        c_len++;
    }
    //printf("%d\n", c_len);
    
    if (wrd>c_len || wrd<1)             //validation
    {
        printf("Invalid Position\n");
        return;
    }
    
    //replace word at position
    word* t = l_pt->next;
    int i=1;
    while(i!=wrd)
    {
        t=t->next;
        i++;
    }
    strcpy(t->w, str);
    //printf("%s\n%s\n", t->w, str);
}

void delete(int ln, int wrd, char* str)
{
    //no of lines
    line* tl = l_head;
    int l_len = 0;
    while(tl!=NULL)                                           
    {
        tl=tl->l_nxt;
        l_len++;
    }
    //take the line pointer to the line to delete from
    line* l_pt = l_head;
    if (ln>l_len || ln<1)
    {
        printf("Invalid Position\n");
        return;
    }
    else
    {
        for (int i = 0; i < ln - 1; i++)                          
        {
            l_pt = l_pt->l_nxt;
        }
    }
    //get the len of the line
    word* wt = l_pt->next;
    int c_len = 0;
    while(wt!=NULL)                                           
    {
        wt=wt->next;
        c_len++;
    }
    //delete the word at position
    if (wrd>c_len+1 || wrd<1)
    {
        printf("Invalid Position\n");
        return;
    }

    word* t1=l_pt->next;
    word* t2=t1->next;
    if (t1->next==NULL)
    {
        l_pt->next=NULL;
        free(t1);
    }
    else if (wrd==1)
    {
        l_pt->next=t2;
        free(t1);
    }
    else
    {
        int i=1;
        while(i!=wrd-1)
        {
            t1=t1->next;
            t2=t1->next;
            i++;
        }
        t1->next=t2->next;
        strcpy(str, t2->w);
        free(t2);
    }

    printf("%s", str);
}

void save_to_file(const char* file_path) 
{
    FILE *file = fopen(file_path, "w");
    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return;
    }

    line* l_temp = l_head;
    while (l_temp != NULL) 
    {
        word* w_temp = l_temp->next;
        while (w_temp != NULL) 
        {
            fprintf(file, "%s ", w_temp->w);
            w_temp = w_temp->next;
        }
        fprintf(file, "\n");
        l_temp = l_temp->l_nxt;
    }

    fclose(file);
    printf("File successfully saved to %s\n", file_path);
}

void saveas_utf8(const char* filename) 
{
    FILE *file = fopen(filename, "w");
    if (file == NULL) 
    {
        printf("Error opening file at path: %s\n", filename);
        return;
    }

    // Write the UTF-8 BOM (Byte Order Mark) to the file to indicate UTF-8 encoding
    unsigned char bom[] = {0xEF, 0xBB, 0xBF};
    size_t bom_written = fwrite(bom, sizeof(bom), 1, file);
    if (bom_written != 1) 
    {
        printf("Error writing BOM to file.\n");
        fclose(file);
        return;
    }

    // Traverse the lines and words, saving them to the file
    line* l_temp = l_head;
    if (l_temp == NULL) 
    {
        printf("No data to write to the file.\n");
    }

    while (l_temp != NULL) 
    {
        word* w_temp = l_temp->next;
        while (w_temp != NULL) 
        {
            if (fprintf(file, "%s ", w_temp->w) < 0) {
                printf("Error writing word to file.\n");
                fclose(file);
                return;
            }
            w_temp = w_temp->next;
        }
        if (fprintf(file, "\n") < 0) 
        {
            printf("Error writing newline to file.\n");
            fclose(file);
            return;
        }
        l_temp = l_temp->l_nxt;
    }

    fclose(file);
    printf("File successfully saved to %s in UTF-8 encoding.\n", filename);
}

void close()
{
    // Free all lines and their words
    while (l_head != NULL) 
    {
        line *l_temp = l_head;
        l_head = l_head->l_nxt;
        
        // Free all words in this line
        while (l_temp->next != NULL) 
        {
            word *w_temp = l_temp->next;
            l_temp->next = w_temp->next;
            free(w_temp);
        }
        
        free(l_temp);
    }
    exit(0);
}

int main()
{
    printf("\n     Praloy's Line Editor Program Written in C Programming Language\n");
    printf("**To Ensure your line is saved please press Enter after completing your line**\n");
    printf("     #'`' is the utility key (Use it to fetch more operational functions)#\n");
    printf("-------------------------------------------------------------------------------\n\n");
    printf("--> ");
    write();
    return 0;
}