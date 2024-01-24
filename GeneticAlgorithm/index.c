#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int num_colors;
int code_length;
char **possible_code;
char *choice;
int max_possible = 0;
int max_gen = 60;
int num_population = 60;

void create_choice();
void create_possible(char *code, int pos);
void checkCode(char *guess_code, char *ans_code, char *get);
char *randomCode();

int main()
{
    int turn = 1;
    int correct = 0;

    scanf("%d", &num_colors);
    scanf("%d", &code_length);

    possible_code = malloc(sizeof(char *) * pow(num_colors, code_length));
    char **guess_code = malloc(sizeof(char *) * max_gen);
    char *ans = malloc(sizeof(char) * (code_length + 1));
    char *code = malloc(sizeof(char) * (code_length + 1));
    char *get = malloc(sizeof(char) * (code_length + 1));

    create_choice();
    create_possible(code, 0);

    // for(int i=0 ; i<max_possible ; i++)
    // {
    //     printf("%s\n",possible_code[i]);
    // }

    guess_code[0] = randomCode();
    printf("%s\n", guess_code[0]);

    while (getchar() != '\n')
        continue;
    scanf("%s", ans);

    checkCode(guess_code[0], ans, get);

    printf("%s", get);

    while (!correct)
    {
        turn++;
        int h = 1;
    }
}

void OnePoint_Crossover(char *code1, char *code2)
{
}

void TwoPoint_Crossover(char *code1, char *code2)
{
}

int fitness_score(char *)
{
    
}

char *randomCode()
{
    char *code = malloc(sizeof(char) * (num_colors + 1));
    for (int i = 0; i < code_length; i++)
    {
        code[i] = 65 + (rand() % num_colors);
        // printf("%c",code[i]);
    }
    code[code_length] = '\0';
    return code;
}

void checkCode(char guess_code[], char ans_code[], char get[])
{
    char ans[code_length];
    char guess[code_length];
    int k = 0;
    for (int i = 0; i < code_length; i++)
    {
        ans[i] = ans_code[i];
        guess[i] = guess_code[i];
        if (guess[i] == ans_code[i])
        {
            get[k++] = 'b';
            guess[i] = ' ';
            ans[i] = ' ';
            // printf("get b\n");
        }
    }
    for (int i = 0; i < code_length; i++)
    {
        if (guess[i] != ' ')
        {
            for (int j = 0; j < code_length; j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (guess[i] == ans[j])
                {
                    get[k++] = 'w';
                    guess[i] = ' ';
                    // printf("get w\n");
                    break;
                }
            }
        }
    }
    while (k < code_length)
    {
        get[k++] = '-';
    }

    get[code_length] = '\0';
}

void create_possible(char *code, int pos)
{
    if (pos < code_length)
    {
        int i = 0;
        while (i < num_colors)
        {
            code[pos] = 65 + i;
            i++;
            create_possible(code, pos + 1);
        }
    }
    else
    {
        possible_code[max_possible] = malloc(sizeof(char) * (code_length + 1));
        for (int i = 0; i < code_length; i++)
        {
            possible_code[max_possible][i] = code[i];
        }
        possible_code[max_possible][code_length] = '\0';
        max_possible++;
    }
}

void create_choice()
{
    choice = malloc(sizeof(char) * num_colors);
    for (int i = 0; i < num_colors; i++)
    {
        choice[i] = 65 + i;
    }
}
