//die.h
#ifndef die
#define die 

class Die {
    
    private: 
        int faces;
        int value;

    public: 
        Die();
        Die(int size);
        int get_face();
        int get_value();
        void roll();
};

#endif