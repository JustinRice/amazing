#ifndef INTEGER_H_
#define INTEGER_H_


using namespace std;

class Integer{
    public:
        Integer(int);
        void set(int);
        int get();
        int getName();
    private:
        int value;
};

Integer::Integer(int i){
    value = 0;
    value = i;
}

void Integer::set(int i){
    value = i;
}

int Integer::get(){
    return value;
}

int Integer::getName(){
    return value;
}



#endif
