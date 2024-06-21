#include <iostream>
#include "Stack.hpp"
#include <map>
#include <string>

int Paranthesis(char * str){
    
    if(str == NULL){
        return 1;
    }
    Stack s(30);
    for(size_t i=0; str[i]!='\0'; i++){
        
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            s.Push(str[i]);
        } else if(str[i] == ')' || str[i] == ']' || str[i] == '}'){
            
            if(s.isEmpty()){
                return 0;
            }
            
            if((str[i] == ')' && s.Top() == '(') ||
               (str[i] == ']' && s.Top() == '[') ||
               (str[i] == '}' && s.Top() == '{')){
                s.Pop();
            } else {
                return 0;
            }
        }
    }
    return s.isEmpty();
}

std::string InfixToPostfix(std::string str){
    
    std::map<int, int> outStack;
    std::map<int, int> inStack;
    
    outStack.insert({'+', 1});
    outStack.insert({'-', 1});
    outStack.insert({'*', 3});
    outStack.insert({'/', 3});
    outStack.insert({'^', 6});
    outStack.insert({'n', 6});
    outStack.insert({'l', 6});
    outStack.insert({'(', 7});
    outStack.insert({')', 0});
    
    inStack.insert({'+', 2});
    inStack.insert({'-', 2});
    inStack.insert({'*', 4});
    inStack.insert({'/', 4});
    inStack.insert({'^', 5});
    inStack.insert({'n', 5});
    inStack.insert({'l', 5});
    inStack.insert({'(', 0});
    
    Stack s(30);
    std::string result;
    size_t i=0;
    
    while(str[i]!='\0'){
        
        char c = str[i];
        if(outStack.count(c) > 0){
            
            if(s.isEmpty() || outStack.at(c) > inStack.at(s.Top())){
                s.Push(c);
                i++;
                
            } else if(outStack.at(c) < inStack.at(s.Top())){
                result.push_back(s.Pop());
                
            } else{
                s.Pop();
                i++;
            }
        } else {
            result.push_back(str[i]);
            i++;
        }
    }
    while(!s.isEmpty()){
        result.push_back(s.Pop());
    }
    return result;
}


std::string InfixToPostfix_simple(std::string str){
    
    std::map<char, int> precedence;
    
    precedence.insert({'+', 1});
    precedence.insert({'-', 1});
    precedence.insert({'*', 2});
    precedence.insert({'/', 2});
    
    Stack s(30);
    size_t i=0;
    std::string result;
    
    while(str[i] != '\0'){
        char c = str[i];
        
        if(precedence.count(c) > 0){
            if(s.isEmpty() || precedence.at(c) > precedence.at(s.Top())){
                s.Push(c);
                i++;
            } else {
                result.push_back(s.Pop());
            }
        } else {
            result.push_back(c);
            i++;
        }
        
    }
    while(!s.isEmpty()){
        result.push_back(s.Pop());
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    /**
    Stack s1(6);
    
    printf("Is empty: %d \n", s1.isEmpty());
    printf("Is full: %d \n", s1.isFull());
    s1.Push(34);
    s1.Push(12);
    s1.Push(3);
    s1.Push(45);
    s1.Push(67);
    s1.Push(102);
    s1.Push(77);
    printf("Is full: %d \n", s1.isFull());
    
    printf("Top is: %d \n", s1.Top());
    printf("Pop: %d \n", s1.Pop());
    printf("Top is: %d \n", s1.Top());
    printf("Is empty: %d \n", s1.isEmpty());
    
    printf("Pop again: %d \n", s1.Pop());
    printf("Peek 0: %d \n", s1.Peek(0));
    printf("Peek 1: %d \n", s1.Peek(1));
    printf("Peek 2: %d \n", s1.Peek(2));
    printf("Peek 3: %d \n", s1.Peek(3));
    printf("Peek 4: %d \n", s1.Peek(4));
    */
    
    char str1[] = "[(a+b)*({c}-d)]";
    printf("Is paranthesis passed: %d\n", Paranthesis(str1));
    
    std::string str2 = "((a+b)*c)-d^e^f";
    std::cout << "Infix to Postfix: " << InfixToPostfix(str2) << " \n";
    
    std::string str3 = "a+b*c-d/e";
    std::cout << "Infix to Postfix: " << InfixToPostfix_simple(str3) << " \n";
    
    
    return 0;
}
