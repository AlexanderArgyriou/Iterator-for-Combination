class CombinationIterator 
{
    private:
        std::string C;
        std::string Comb;
        int Position;
        int L;
        std::vector< std::string > PossibleComb;
        
        inline void FindPossibleCobinations(int Start, int End, int Index) noexcept
        {
            if( Index == L )
            {
                PossibleComb.push_back( Comb );
                return;  
            }   // if
            
            for ( int i = Start; i <= End && End - i + 1 >= L - Index; i++ )  
            {  
                Comb[Index] = C[i];  
                FindPossibleCobinations( i + 1, End, Index + 1 );  
            }  // for
        }   // FindPossibleCobinations
    
    public:
        inline CombinationIterator(string c, int l) noexcept
            : C(c), L(l), Position(0)
        {
            for( int i = 0; i < l; ++i )
                Comb += '\0';
                
            FindPossibleCobinations( 0, C.length() - 1, 0 );
        }  // Constructor
        
        inline ~CombinationIterator() noexcept
        {
            Comb = "";
            C = "";
            Position = L = 0;
            PossibleComb.clear();
        }   // Destructor
    
        inline std::string next() noexcept { return PossibleComb[Position++]; }   // next
        inline bool hasNext() const noexcept { return PossibleComb.size() != Position; }  // hasNext
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
