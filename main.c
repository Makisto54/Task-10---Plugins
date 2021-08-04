#include "functions.h"

int comparator(const int *i, const int *j)
{
    return *i - *j;
}

void print_commands(int *commands_mas)
{
    for (int i = 0; i < COMMANDS; i++)
    {
        switch(commands_mas[i])
        {
            case 1:
                printf("1 - Add\n");
                break;
            case 2:
                printf("2 - Sub\n");
                break;            
            case 3:
                printf("3 - Mul\n");
                break;            
            case 4:
                printf("4 - Div\n");
                break;            
            default:
                break;              
        }
    }
    printf("5 - Exit\n");
}

int main(void)
{
    int key = 0;

    void *(*func)();
    void *handles[COMMANDS] = {NULL};

    int commands_mas[COMMANDS] = {0};

    printf("Input your commands:\n");
    printf("1 - Add\n");
    printf("2 - Sub\n");
    printf("3 - Mul\n");
    printf("4 - Div\n");

    for (int i = 0; i < COMMANDS; i++)
    {
        fscanf(stdin, "%d", &commands_mas[i]);
        switch(commands_mas[i])
        {
            case 1:
                if(NULL == handles[0])
                {
                    handles[0] = dlopen("libadd.so", RTLD_LAZY);
                    if(!handles[0]) 
                    {
                        perror(dlerror());
                        exit(1);
                    }                   
                }
                else
                {
                    commands_mas[i] = 0;
                }
                break;
            case 2:
                if(NULL == handles[1])
                {
                    handles[1] = dlopen("libsub.so", RTLD_LAZY);
                    if(!handles[1]) 
                    {
                        perror(dlerror());
                        exit(1);
                    }                   
                }
                else
                {
                    commands_mas[i] = 0;
                }
                break;            
            case 3:
                if(NULL == handles[2])
                {
                    handles[2] = dlopen("libmul.so", RTLD_LAZY);
                    if(!handles[2]) 
                    {
                        perror(dlerror());
                        exit(1);
                    }                   
                }
                else
                {
                    commands_mas[i] = 0;
                }
                break;            
            case 4:
                if(NULL == handles[3])
                {
                    handles[3] = dlopen("libdiv.so", RTLD_LAZY);
                    if(!handles[3]) 
                    {
                        perror(dlerror());
                        exit(1);
                    }                   
                }
                else
                {
                    commands_mas[i] = 0;
                }
                break;            
            default:
                break;             
        }
    }

    qsort(commands_mas, COMMANDS, sizeof(int), (int(*) (const void *, const void *)) comparator);
    while (key != 5)
    {    
        print_commands(commands_mas);
        fscanf(stdin, "%d", &key);

        switch(key)
        {
            case 1:
                if (NULL != handles[0])
                {
                    func = dlsym(handles[0], "add");
                    if (dlerror() != NULL)
                    {
                        perror(dlerror());
                        exit(1);
                    }
                    (*func)();                   
                }
                break;
            case 2:
                if (NULL != handles[1])
                {
                    func = dlsym(handles[1], "sub");
                    if (dlerror() != NULL)
                    {
                        perror(dlerror());
                        exit(1);
                    }
                    (*func)();                   
                }
                break;            
            case 3:
                if (NULL != handles[2])
                {
                    func = dlsym(handles[2], "mul");
                    if (dlerror() != NULL)
                    {
                        perror(dlerror());
                        exit(1);
                    }
                    (*func)();                   
                }
                break;            
            case 4:
                if (NULL != handles[3])
                {
                    func = dlsym(handles[3], "divide");
                    if (dlerror() != NULL)
                    {
                        perror(dlerror());
                        exit(1);
                    }
                    (*func)();                   
                }
                break;            
            default:
                break;              
        }
    }

    for (int i = 0; i < COMMANDS; i++)
    {
        if (handles[i] != NULL)
        {
            dlclose(handles[i]);
        }
    }

    return 0;
}