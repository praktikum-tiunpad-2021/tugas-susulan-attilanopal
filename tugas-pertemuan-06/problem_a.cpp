#include "problem_a.hpp"

using namespace strukdat::stack;

template <typename T>
int getMax(Stack<T> Top) {
    pointer<T> dump = nullptr;
    int hasil = 0;
    if (isEmpty(Top)){
        hasil = 0;
    }
    else{
        int maximal = 0;
        while(!(isEmpty(Top))){
            if (maximal < peek(Top)){
                maximal = peek(Top);
            }
            pop(Top, dump);
            delete dump;
        }
        hasil = maximal;
    }
    return hasil;
}

    
template <typename T>               // Fungsi untuk menjumlahkan nilai elemen
int sumElement(Stack<T> Top){
    pointer<T> Tmp = Top;
    int sum = 0;
    while (Tmp!= nullptr)
    {
        sum += Tmp->data;
        Tmp = Tmp->next;
    }
    return sum;
}

template <typename T>
int getEqualStack(Stack<T> Top1, Stack<T> Top2, Stack<T> Top3)
{
    int hasil = 0;
    if (isEmpty(Top1) || isEmpty(Top2) || isEmpty(Top3)){
        hasil = 0;
    }
    else{
        pointer<T> delTop = nullptr;
        int sum1 = 0;
        int sum2 = 0;
        int sum3 = 0;
        int max = 0;
        bool equal = 0;

        while (equal != 1){
            sum1 = sumElement(Top1);
            sum2 = sumElement(Top2);
            sum3 = sumElement(Top3);
            
            if (sum1 > sum2){
                if (sum1 > sum3){
                    max = 1;
                }
                else{
                    max = 3;
                }
            }
            else{
                if (sum2 > sum3){
                    max = 2;
                }
                else{
                    max = 3; 
                }
            }

            switch(max){
                case 1:
                    pop(Top1, delTop);
                    delete delTop;
                    break;
                case 2:
                    pop(Top2, delTop);
                    delete delTop;
                    break;
                case 3:
                    pop(Top3, delTop);
                    delete delTop;
                    break;
            }

            if (sum1 == sum2 && sum2 == sum3){
                equal = 1;
                hasil = sum1;
            }
        }
    }

    return hasil;
}

bool isBracketBalanced(std::string expression)
{
    pointer<char> newElement = nullptr;
    Stack<char> stringElement = nullptr;
    pointer<char> dump = nullptr;
    createStack(stringElement);
    int length = expression.length();
    
    for (int i=length-1; i>=0; i--){
        createElement(newElement, expression[i]);
        stringElement = push(stringElement, newElement);
        std::cout << i;
    }

    bool check = true;

    if (isEmpty(stringElement)){
        check = false;
    }
    else{
        char bracketCheck, bracketCheck2;
        pointer<char> last;

        if (length % 2 == 1){
            check = false;
        }
        else{
            for (int i=0; i<(length / 2); i++){
                bracketCheck = peek(stringElement);
                switch(bracketCheck){
                    case '(':
                        bracketCheck2 = ')';
                        break;
                    case '[':
                        bracketCheck2 = ']';
                        break;
                    case '{':
                        bracketCheck2 = '}';
                        break;
                }

                last = lastNode(stringElement);
                if (last->data != bracketCheck2){
                    check = false;
                    delete stringElement;
                    break;
                }
                else{
                    pop(stringElement, dump);
                    delete dump;
                    delete last;
                }
            }
        }
    }

    return check;
}