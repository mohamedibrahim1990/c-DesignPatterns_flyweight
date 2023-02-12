#include <iostream>
#include <boost/bimap.hpp>

typedef uint32_t key;

struct User{
    User(const std::string& first_name, const std::string& last_name): first_name{add(first_name)}, last_name{add(last_name)}{}
protected:
    key first_name, last_name;
    static boost::bimap<key, std::string> names;
    static key seed;
    static key add(const std::string& s);
};

key User::add(const std::string& s){
    auto it= names.right.find(s);
    if(it==names.right.end()){
        //add it
        names.insert({++seed, s});
        return seed;
    }
    return it->second;
}

int main(){
    std::cout << "hello world" <<std::endl;
}
