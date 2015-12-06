
class Block
{
    private:
        blockOption;

    public:

        enum blockOption
        {
            Opt_X, //X
            Opt_O, //O
            Opt_E  //Empty
        }

        Block();

        void setBlock(blockOption val);

        blockOption getVal();
}
