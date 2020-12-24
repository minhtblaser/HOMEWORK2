#include<stdio.h>
#include<string.h>
typedef struct Datetime {
    int day, month, year;
};
typedef struct Student {
    char name[50];
    float gpa;
    Datetime date_of_birth;
}; 
typedef struct Students {
    Student students[50];
    int amount;
};
bool isLeapYear(int year);
bool isValid(Datetime check);
void enter(Datetime &current);
void enter(Student &input);
void enter(Students &input);
void printValue(Datetime ouput);
void printValue(Student ouput);
void printValue(Students ouput);

int main(){
    Students list;
    char search_name[50];
    enter(list);
    printValue(list);
    ascSortByName(list);
    printValue(list);
    printAmountStudentsHaveScholarship(list);
    digitsStudentsHaveScholarship(list);
    printf("\nname to search: ");
    fflush(stdin);
    gets(search_name);
    digitsStudentByName(list,search_name);
    return 0;
}
bool isLeapYear(int year){
    return year % 4 == 0;
}
bool isValid(Datetime date){
    bool is_valid = true;
    if ((date.month < 1 || date.month > 12) || date.day < 1){
        is_valid = false;
    } else {
        switch ((date.month))
        {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (date.day > 31){
                is_valid = false;
            }
            break;
        case  4: case 6: case 9: case 11:
            if (date.day > 30){
                is_valid = false;
            }
            break;
        case 2: 
            if (isLeapYear(date.year) && date.day > 29){
                is_valid = false;
            } else if (!isLeapYear(date.year) && date.date > 28){
                is_valid = false;
            }
            break;
        }
    }
    return is_valid;
}
void enter(Datetime &date){
    do{
        printf("\nenter day: ");
        scanf("%d", date.day);
        printf("\enter month: ");
        scanf("%d", date.month);
        printf("\nenter year: ");
        scanf("%d", date.year);
        if(!isValid(date)){
            printf("enter again: ");
        }
    } while (!isValid(date))
}
void enter(Student &input){
    fflush(stdin);
    gets(input.name);
    printf("\nenter date of birth: ");
    enter(input.date_of_birth);
    printf("\nenter GPA: ");
    scanf("%d", &input.gpa);
}
void enter(Students &input){
    printf("\nenter amount of student: ");
    scanf("%d", &input.amount);
    for(int position = 0; position < input.amount; position++){
        enter(input.students[position]);
    }
}
void printValue(Datetime ouput){
    printf("%d/%d/%d", ouput.day, output.month, output.year);
}
void printValue(Student ouput){
    printf("\n{\"%s\", ", output.name);
    printValue(ouput.date_of_birth);
    printf(", %.2f }", ouput.gpa);
}
void printValue(Students output){
    printf("\nList of student");
    for(int position = 0; position < output.amount; position++){
        printValue(output.students[position]);
    }
}
void ascSortByGPA(Students &source){
    Student temp;
    for(int pre=0; pre < source.amount-1;pre++){
        for(int next = pre+1; next < source.amount;next++){
            if(source.students[pre].gpa>source.students[next].gpa){
                temp = source.students[pre];
                source.students[pre] = source.students[next];
                source.students[next] = temp;
            }
        }
    }
}
void ascSortByName(Students &source){
    Student temp;
    for(int pre=0; pre < source.amount-1;pre++){
        for(int next = pre+1; next < source.amount;next++){
            if(strcmp(source.students[pre].name, source.students[next].name)>0){
                temp = source.students[pre];
                source.students[pre] = source.students[next];
                source.students[next] = temp;
            }
        }
    }
}
int countStudentsHaveScholarship(Students source){
    int counter = 0;
    for(int position = 0; position < source.amount;position++){
        if(source.students[position].gpa>=7){
            counter++;   
        }
    }
    return counter;
}
void printAmountStudentsHaveScholarship(Students source){
    int counter = countStudentsHaveScholarship(source);
    printf("\nnumber of students have scholarship: %d",counter);
}
void digitsStudentsHaveScholarship(Students source){
    int counter = 0;
    printf("\nlist of students have scholarship: ");
    for(int position = 0; position < source.amount;position++){
        if(source.students[position].gpa>=7){
            printValue(source.students[position]);  
        }
    }
}
Students findStudentsByName(Students source,char search_name[]){
    Students dest;
    dest.amount = 0;
    for(int position=0;position<source.amount;position++){
        if(strcmp(source.students[position].name,search_name)==0){
            dest.amount++;
            dest.students[dest.amount-1] = source.students[position];
        }
    }
    return dest;
}
void digitsStudentByName(Students source, char search_name[]){
    Students dest = findStudentsByName(source, search_name);
    for(int position = 0; position<dest.amount;position++){
        printValue(dest.students[position]);
    } 
}
