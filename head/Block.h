#ifndef BLOCK_H
#define BLOCK_H
class Block
{
    
    public:

        enum blockOption
        {
            Opt_X, //X
            Opt_O, //O
            Opt_E  //Empty
        };

        Block();

        void setVal(blockOption val);

        blockOption getVal();

        char blockToChar();

    private:
        blockOption value;

};

#endif
