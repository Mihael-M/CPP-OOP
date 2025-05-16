#include <iostream>
#include <fstream>



size_t get_file_size(std::fstream& is){
    if(!is.good())
        return -1;
    
    size_t curr = is.tellg();
    is.seekg(0,std::ios::end);
    size_t res = is.tellg();
    is.seekg(curr,std::ios::beg);
    return res;
}

bool is_symbol(char ch){
    return ch >= 32 && ch <= 127;
}

size_t get_symbols(std::fstream& is){
    if(!is.good())
        return -1;
    
    size_t curr = is.tellg();
    size_t res = 0;
    while(!is.eof()){
        if(is_symbol(is.get()))
            res++;
    }
    is.clear();
    is.seekg(curr,std::ios::beg);
    return res;
}
size_t get_symbols(std::fstream& is, char ch){
    if(!is.good())
        return -1;
    
    size_t curr = is.tellg();
    size_t res = 0;
    char temp;
    while(is.get(temp)){
        if(temp == ch)
            res++;
    }
    is.clear();
    is.seekg(curr,std::ios::beg);
    return res;
}


size_t get_words_count(std::fstream& is){
    if(!is.good())
        return -1;
    
    size_t curr = is.tellg();
    size_t res = 0;
    bool is_word = false;
    char ch;
    while(is.get(ch)){
        if(is_symbol(ch))
        {
            if(!is_word)
            {
                res++;
                is_word = true;
            }
        }
        else{
            is_word = false;
        }
    }
    is.clear();
    is.seekg(curr,std::ios::beg);
    return res;
}

size_t get_rows_count(std::fstream& is){
    return get_symbols(is,'\n');
}

size_t get_not_empty_rows_count(std::fstream& is){
    if(!is.good())
        return -1;
    
    int res = 0;
    size_t curr = is.tellg();
    char buff[1024];
    
    while(is.getline(buff, sizeof(buff)))
    {
        if(buff[0] != '\0')
            res++;
    }
    is.clear();
    is.seekg(curr,std::ios::beg);
    return res;
}

double get_symbol_percentage(std::fstream& is) {
    if (!is.good()) return 0.0;

    size_t file_size = get_file_size(is);
    if (file_size == 0) return 0.0;

    size_t symbol_count = get_symbols(is);
    return (symbol_count / static_cast<double>(file_size)) * 100;
}

void print_statistics(std::fstream& is)
{
    if(!is.good())
        return;
    
    std::cout<<"All the symbols in the file are: " << get_file_size(is) << std::endl;
    std::cout<<std::endl;
    std::cout<<"All the valid symbols int the file are: "<<get_symbols(is) << std::endl;
    std::cout<<std::endl;
    std::cout<<"All the words in the file are: "<<get_words_count(is)<<std::endl;
    std::cout<<std::endl;
    std::cout<<"All the rows in the file are: "<<get_rows_count(is)<<std::endl;
    std::cout<<std::endl;
    std::cout<<"All the nonempty rows in the file are: "<<get_not_empty_rows_count(is)<<std::endl;
    std::cout<<std::endl;
    std::cout<<"The precentage of the valid symbols from all the ones are: " << get_symbol_percentage(is)<<"%"<<std::endl;
}
void helper()
{
    std::cout<<"                    Options                     "<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"c - number of symbols" <<std::endl;
    std::cout<<"C - number of symbols with code between 32 and 127 (valid)"<<std::endl;
    std::cout<<"w - number of words"<<std::endl;
    std::cout<<"l - number of rows" <<std::endl;
    std::cout<<"L - number of nonempty rows"<<std::endl;
    std::cout<<"s - show statistics"<<std::endl;
    std::cout<<"h - help" << std::endl;
    std::cout<<"a - open another file" << std::endl;
    std::cout<<"e - exit" << std::endl;
    
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Enter filename:  " << std::endl;
}

void enter_command(std::fstream& is,char ch,bool& end,bool& file)
{
    if(!is.good())
    {
        std::cout<<"ERROR"<<std::endl;
        abort();
        return;
    }
    switch (ch) {
        case 'c':
            std::cout<<"All the symbols in the file are: " << get_file_size(is) << std::endl;
            break;
        case 'C':
            std::cout<<"All the valid symbols int the file are: "<<get_symbols(is) << std::endl;
            break;
        case 'w':
            std::cout<<"All the words in the file are: "<<get_words_count(is)<<std::endl;
            break;
        case 'l':
            std::cout<<"All the rows in the file are: "<<get_rows_count(is)<<std::endl;
            break;
        case 'L':
            std::cout<<"All the nonempty rows in the file are: "<<get_not_empty_rows_count(is)<<std::endl;
            break;
        case 's':
            print_statistics(is);
            break;
        case 'h':
            helper();
            break;
        case 'a':
            file=true;
            break;
        case 'e':
            end = true;
            break;
        default:
            std::cout << "Invalid command!" << std::endl;
            helper();
            break;
    }
    helper();
      
        
}



int main(int argc, const char * argv[]) {
    char fileName[100];
    helper();
    
   
    
    bool file = false;
    bool exit = false;
    
    std::cin>>fileName;
    std::fstream is(fileName,std::ios::in);
    
    if(!is)
    {
        std::cout<<"Error opening the file!!!";
        return 0;
    }
    do{
        char ch;
        std::cin>>ch;
        enter_command(is, ch,exit,file);
        
        if(file)
        {
            std::cin>>fileName;
            is.close();
             is.open(fileName,std::ios::in);
            if(!is)
            {
                std::cout<<"Error opening the file!!!";
                return 0;
            }
            file = false;
        }
        
    }
    while(!exit);
    
    return 0;
}
