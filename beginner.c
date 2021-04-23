
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 
#define MAX_LINE_SIZE 200
struct Result{
    char name[20];
    float oneResult[3];
}result[5];

typedef Result* Rpointer;

void initFromFile(const char* filename);
bool compare(Result a,Result b);
void swap(Result a,Result b);
void printResult(Rpointer result,int n);


int main(int argc, const char * argv[]) {
    
    initFromFile(argv[1]);
    printResult(result,5);
    swap(result[1],result[2]);
    bool a = compare(result[1],result[2]);
    printResult(result,5);
    return 0;
}

void initFromFile(const char* filename)
{
    char file_name[]="data.csv";
    
    FILE *fp;
    fp = fopen(filename, "r");
    
    if (!fp) {
        fprintf(stderr, "failed to open file for reading\n");
    } 
    
    char line[MAX_LINE_SIZE];
    char *item = NULL;

    int i=0;

    
    while(fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        if(i==0){
            i++;  
            continue;
        }
    
              
        item = strtok(line, ",");
        int j = 0;
        while( item != NULL ) {
            if(j==0){
               strcpy(result[i-1].name,item);
              // printf("name : %s",item);
            }
            else
            {
                result[i-1].oneResult[j-1] = atof(item);
            }
            j++;
            item = strtok(NULL, ",");
        }
        printf("precess one line\n");
        i++;
    }
    
    fclose (fp);

}

bool compare(Result a,Result b)
{
    return a.oneResult[0]<b.oneResult[0]?true:false;
  }

void swap(Result a, Result b)
{
    printf("swap, %s %s\n",a.name,b.name);
    struct Result change;
    change = a;
    a = b;
    b = change;
    printf("swap result, %s,%s \n",a.name,b.name);

}


void printResult(Rpointer result, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%s, %f, %f, %f \n",result[i].name,result[i].oneResult[0],result[i].oneResult[1],result[i].oneResult[2]);
    }
}
