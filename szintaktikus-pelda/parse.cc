// Generated by Bisonc++ V4.05.00 on Thu, 31 Mar 2016 15:02:48 +0200

// $insert class.ih
#include "Parser.ih"

// The FIRST element of SR arrays shown below uses `d_type', defining the
// state's type, and `d_lastIdx' containing the last element's index. If
// d_lastIdx contains the REQ_TOKEN bitflag (see below) then the state needs
// a token: if in this state d_token__ is _UNDETERMINED_, nextToken() will be
// called

// The LAST element of SR arrays uses `d_token' containing the last retrieved
// token to speed up the (linear) seach.  Except for the first element of SR
// arrays, the field `d_action' is used to determine what to do next. If
// positive, it represents the next state (used with SHIFT); if zero, it
// indicates `ACCEPT', if negative, -d_action represents the number of the
// rule to reduce to.

// `lookup()' tries to find d_token__ in the current SR array. If it fails, and
// there is no default reduction UNEXPECTED_TOKEN__ is thrown, which is then
// caught by the error-recovery function.

// The error-recovery function will pop elements off the stack until a state
// having bit flag ERR_ITEM is found. This state has a transition on _error_
// which is applied. In this _error_ state, while the current token is not a
// proper continuation, new tokens are obtained by nextToken(). If such a
// token is found, error recovery is successful and the token is
// handled according to the error state's SR table and parsing continues.
// During error recovery semantic actions are ignored.

// A state flagged with the DEF_RED flag will perform a default
// reduction if no other continuations are available for the current token.

// The ACCEPT STATE never shows a default reduction: when it is reached the
// parser returns ACCEPT(). During the grammar
// analysis phase a default reduction may have been defined, but it is
// removed during the state-definition phase.

// So:
//      s_x[] = 
//      {
//                  [_field_1_]         [_field_2_]
//
// First element:   {state-type,        idx of last element},
// Other elements:  {required token,    action to perform},
//                                      ( < 0: reduce, 
//                                          0: ACCEPT,
//                                        > 0: next state)
// Last element:    {set to d_token__,    action to perform}
//      }

// When the --thread-safe option is specified, all static data are defined as
// const. If --thread-safe is not provided, the state-tables are not defined
// as const, since the lookup() function below will modify them


namespace // anonymous
{
    char const author[] = "Frank B. Brokken (f.b.brokken@rug.nl)";

    enum 
    {
        STACK_EXPANSION = 5     // size to expand the state-stack with when
                                // full
    };

    enum ReservedTokens
    {
        PARSE_ACCEPT     = 0,   // `ACCEPT' TRANSITION
        _UNDETERMINED_   = -2,
        _EOF_            = -1,
        _error_          = 256
    };
    enum StateType       // modify statetype/data.cc when this enum changes
    {
        NORMAL,
        ERR_ITEM,
        REQ_TOKEN,
        ERR_REQ,    // ERR_ITEM | REQ_TOKEN
        DEF_RED,    // state having default reduction
        ERR_DEF,    // ERR_ITEM | DEF_RED
        REQ_DEF,    // REQ_TOKEN | DEF_RED
        ERR_REQ_DEF // ERR_ITEM | REQ_TOKEN | DEF_RED
    };    
    struct PI__     // Production Info
    {
        size_t d_nonTerm; // identification number of this production's
                            // non-terminal 
        size_t d_size;    // number of elements in this production 
    };

    struct SR__     // Shift Reduce info, see its description above
    {
        union
        {
            int _field_1_;      // initializer, allowing initializations 
                                // of the SR s_[] arrays
            int d_type;
            int d_token;
        };
        union
        {
            int _field_2_;

            int d_lastIdx;          // if negative, the state uses SHIFT
            int d_action;           // may be negative (reduce), 
                                    // postive (shift), or 0 (accept)
            size_t d_errorState;    // used with Error states
        };
    };

    // $insert staticdata
    
// Productions Info Records:
PI__ const s_productionInfo[] = 
{
     {0, 0}, // not used: reduction values are negative
     {284, 1}, // 1: start ->  expressions
     {285, 0}, // 2: expressions ->  <empty>
     {285, 2}, // 3: expressions ->  elements expressions
     {286, 1}, // 4: elements ->  loop
     {286, 1}, // 5: elements ->  elag
     {286, 1}, // 6: elements ->  io
     {286, 1}, // 7: elements ->  erta
     {286, 1}, // 8: elements (END) ->  END
     {287, 4}, // 9: loop (WHILE) ->  WHILE logical elements WEND
     {288, 5}, // 10: elag (IF) ->  IF logical THEN elements ENDIF
     {288, 7}, // 11: elag (IF) ->  IF logical THEN elements ELSE elements ENDIF
     {290, 4}, // 12: erta (LET) ->  LET AZON EQUAL egesz
     {290, 4}, // 13: erta (LET) ->  LET AZON EQUAL valtnum
     {293, 3}, // 14: valtnum (OPEN) ->  OPEN valtnum CLOSE
     {293, 1}, // 15: valtnum (AZON) ->  AZON
     {293, 1}, // 16: valtnum (NUMBER) ->  NUMBER
     {294, 1}, // 17: kifejezes ->  egesz
     {294, 1}, // 18: kifejezes ->  logical
     {291, 3}, // 19: logical (OPEN) ->  OPEN logical CLOSE
     {291, 3}, // 20: logical (EQUAL) ->  a EQUAL a
     {291, 3}, // 21: logical (LT) ->  a LT a
     {291, 3}, // 22: logical (GT) ->  a GT a
     {291, 3}, // 23: logical (LE) ->  a LE a
     {291, 3}, // 24: logical (GE) ->  a GE a
     {291, 3}, // 25: logical (AND) ->  logical AND logical
     {291, 3}, // 26: logical (OR) ->  logical OR logical
     {291, 2}, // 27: logical (NOT) ->  NOT logical
     {292, 3}, // 28: egesz (OPEN) ->  OPEN egesz CLOSE
     {292, 3}, // 29: egesz (PLUS) ->  a PLUS a
     {292, 3}, // 30: egesz (MINUS) ->  a MINUS a
     {292, 3}, // 31: egesz (MULTI) ->  a MULTI a
     {292, 3}, // 32: egesz (DIV) ->  a DIV a
     {292, 3}, // 33: egesz (MOD) ->  a MOD a
     {295, 1}, // 34: a ->  egesz
     {295, 1}, // 35: a ->  valtnum
     {289, 2}, // 36: io (PRINT) ->  PRINT kifejezes
     {289, 2}, // 37: io (PRINT) ->  PRINT valtnum
     {289, 2}, // 38: io (INPUT) ->  INPUT AZON
     {296, 1}, // 39: start_$ ->  start
};

// State info and SR__ transitions for each state.


SR__ s_0[] =
{
    { { REQ_DEF}, { 14} },               
    { {     284}, {  1} }, // start      
    { {     285}, {  2} }, // expressions
    { {     286}, {  3} }, // elements   
    { {     287}, {  4} }, // loop       
    { {     288}, {  5} }, // elag       
    { {     289}, {  6} }, // io         
    { {     290}, {  7} }, // erta       
    { {     257}, {  8} }, // END        
    { {     263}, {  9} }, // WHILE      
    { {     259}, { 10} }, // IF         
    { {     266}, { 11} }, // PRINT      
    { {     265}, { 12} }, // INPUT      
    { {     258}, { 13} }, // LET        
    { {       0}, { -2} },               
};

SR__ s_1[] =
{
    { { REQ_TOKEN}, {            2} }, 
    { {     _EOF_}, { PARSE_ACCEPT} }, 
    { {         0}, {            0} }, 
};

SR__ s_2[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -1} }, 
};

SR__ s_3[] =
{
    { { REQ_DEF}, { 13} },               
    { {     285}, { 14} }, // expressions
    { {     286}, {  3} }, // elements   
    { {     287}, {  4} }, // loop       
    { {     288}, {  5} }, // elag       
    { {     289}, {  6} }, // io         
    { {     290}, {  7} }, // erta       
    { {     257}, {  8} }, // END        
    { {     263}, {  9} }, // WHILE      
    { {     259}, { 10} }, // IF         
    { {     266}, { 11} }, // PRINT      
    { {     265}, { 12} }, // INPUT      
    { {     258}, { 13} }, // LET        
    { {       0}, { -2} },               
};

SR__ s_4[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -4} }, 
};

SR__ s_5[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -5} }, 
};

SR__ s_6[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -6} }, 
};

SR__ s_7[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -7} }, 
};

SR__ s_8[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -8} }, 
};

SR__ s_9[] =
{
    { { REQ_TOKEN}, {  9} },           
    { {       291}, { 15} }, // logical
    { {       268}, { 16} }, // OPEN   
    { {       295}, { 17} }, // a      
    { {       281}, { 18} }, // NOT    
    { {       292}, { 19} }, // egesz  
    { {       293}, { 20} }, // valtnum
    { {       270}, { 21} }, // AZON   
    { {       267}, { 22} }, // NUMBER 
    { {         0}, {  0} },           
};

SR__ s_10[] =
{
    { { REQ_TOKEN}, {  9} },           
    { {       291}, { 23} }, // logical
    { {       268}, { 16} }, // OPEN   
    { {       295}, { 17} }, // a      
    { {       281}, { 18} }, // NOT    
    { {       292}, { 19} }, // egesz  
    { {       293}, { 20} }, // valtnum
    { {       270}, { 21} }, // AZON   
    { {       267}, { 22} }, // NUMBER 
    { {         0}, {  0} },           
};

SR__ s_11[] =
{
    { { REQ_TOKEN}, { 10} },             
    { {       294}, { 24} }, // kifejezes
    { {       293}, { 25} }, // valtnum  
    { {       292}, { 26} }, // egesz    
    { {       291}, { 27} }, // logical  
    { {       268}, { 16} }, // OPEN     
    { {       270}, { 21} }, // AZON     
    { {       267}, { 22} }, // NUMBER   
    { {       295}, { 17} }, // a        
    { {       281}, { 18} }, // NOT      
    { {         0}, {  0} },             
};

SR__ s_12[] =
{
    { { REQ_TOKEN}, {  2} },        
    { {       270}, { 28} }, // AZON
    { {         0}, {  0} },        
};

SR__ s_13[] =
{
    { { REQ_TOKEN}, {  2} },        
    { {       270}, { 29} }, // AZON
    { {         0}, {  0} },        
};

SR__ s_14[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -3} }, 
};

SR__ s_15[] =
{
    { { REQ_TOKEN}, { 14} },            
    { {       286}, { 30} }, // elements
    { {       282}, { 31} }, // AND     
    { {       283}, { 32} }, // OR      
    { {       287}, {  4} }, // loop    
    { {       288}, {  5} }, // elag    
    { {       289}, {  6} }, // io      
    { {       290}, {  7} }, // erta    
    { {       257}, {  8} }, // END     
    { {       263}, {  9} }, // WHILE   
    { {       259}, { 10} }, // IF      
    { {       266}, { 11} }, // PRINT   
    { {       265}, { 12} }, // INPUT   
    { {       258}, { 13} }, // LET     
    { {         0}, {  0} },            
};

SR__ s_16[] =
{
    { { REQ_TOKEN}, {  9} },           
    { {       291}, { 33} }, // logical
    { {       292}, { 34} }, // egesz  
    { {       293}, { 35} }, // valtnum
    { {       268}, { 16} }, // OPEN   
    { {       295}, { 17} }, // a      
    { {       281}, { 18} }, // NOT    
    { {       270}, { 21} }, // AZON   
    { {       267}, { 22} }, // NUMBER 
    { {         0}, {  0} },           
};

SR__ s_17[] =
{
    { { REQ_TOKEN}, { 11} },         
    { {       280}, { 36} }, // EQUAL
    { {       277}, { 37} }, // LT   
    { {       276}, { 38} }, // GT   
    { {       278}, { 39} }, // LE   
    { {       279}, { 40} }, // GE   
    { {       274}, { 41} }, // PLUS 
    { {       275}, { 42} }, // MINUS
    { {       271}, { 43} }, // MULTI
    { {       272}, { 44} }, // DIV  
    { {       273}, { 45} }, // MOD  
    { {         0}, {  0} },         
};

SR__ s_18[] =
{
    { { REQ_TOKEN}, {  9} },           
    { {       291}, { 46} }, // logical
    { {       268}, { 16} }, // OPEN   
    { {       295}, { 17} }, // a      
    { {       281}, { 18} }, // NOT    
    { {       292}, { 19} }, // egesz  
    { {       293}, { 20} }, // valtnum
    { {       270}, { 21} }, // AZON   
    { {       267}, { 22} }, // NUMBER 
    { {         0}, {  0} },           
};

SR__ s_19[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -34} }, 
};

SR__ s_20[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -35} }, 
};

SR__ s_21[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -15} }, 
};

SR__ s_22[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -16} }, 
};

SR__ s_23[] =
{
    { { REQ_TOKEN}, {  4} },        
    { {       260}, { 47} }, // THEN
    { {       282}, { 31} }, // AND 
    { {       283}, { 32} }, // OR  
    { {         0}, {  0} },        
};

SR__ s_24[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -36} }, 
};

SR__ s_25[] =
{
    { { REQ_DEF}, {  11} },         
    { {     257}, { -37} }, // END  
    { {     258}, { -37} }, // LET  
    { {     259}, { -37} }, // IF   
    { {     261}, { -37} }, // ELSE 
    { {     262}, { -37} }, // ENDIF
    { {     263}, { -37} }, // WHILE
    { {     264}, { -37} }, // WEND 
    { {     265}, { -37} }, // INPUT
    { {     266}, { -37} }, // PRINT
    { {   _EOF_}, { -37} }, // _EOF_
    { {       0}, { -35} },         
};

SR__ s_26[] =
{
    { { REQ_DEF}, {  11} },         
    { {     257}, { -17} }, // END  
    { {     258}, { -17} }, // LET  
    { {     259}, { -17} }, // IF   
    { {     261}, { -17} }, // ELSE 
    { {     262}, { -17} }, // ENDIF
    { {     263}, { -17} }, // WHILE
    { {     264}, { -17} }, // WEND 
    { {     265}, { -17} }, // INPUT
    { {     266}, { -17} }, // PRINT
    { {   _EOF_}, { -17} }, // _EOF_
    { {       0}, { -34} },         
};

SR__ s_27[] =
{
    { { REQ_DEF}, {   3} },       
    { {     282}, {  31} }, // AND
    { {     283}, {  32} }, // OR 
    { {       0}, { -18} },       
};

SR__ s_28[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -38} }, 
};

SR__ s_29[] =
{
    { { REQ_TOKEN}, {  2} },         
    { {       280}, { 48} }, // EQUAL
    { {         0}, {  0} },         
};

SR__ s_30[] =
{
    { { REQ_TOKEN}, {  2} },        
    { {       264}, { 49} }, // WEND
    { {         0}, {  0} },        
};

SR__ s_31[] =
{
    { { REQ_TOKEN}, {  9} },           
    { {       291}, { 50} }, // logical
    { {       268}, { 16} }, // OPEN   
    { {       295}, { 17} }, // a      
    { {       281}, { 18} }, // NOT    
    { {       292}, { 19} }, // egesz  
    { {       293}, { 20} }, // valtnum
    { {       270}, { 21} }, // AZON   
    { {       267}, { 22} }, // NUMBER 
    { {         0}, {  0} },           
};

SR__ s_32[] =
{
    { { REQ_TOKEN}, {  9} },           
    { {       291}, { 51} }, // logical
    { {       268}, { 16} }, // OPEN   
    { {       295}, { 17} }, // a      
    { {       281}, { 18} }, // NOT    
    { {       292}, { 19} }, // egesz  
    { {       293}, { 20} }, // valtnum
    { {       270}, { 21} }, // AZON   
    { {       267}, { 22} }, // NUMBER 
    { {         0}, {  0} },           
};

SR__ s_33[] =
{
    { { REQ_TOKEN}, {  4} },         
    { {       269}, { 52} }, // CLOSE
    { {       282}, { 31} }, // AND  
    { {       283}, { 32} }, // OR   
    { {         0}, {  0} },         
};

SR__ s_34[] =
{
    { { REQ_DEF}, {   2} },         
    { {     269}, {  53} }, // CLOSE
    { {       0}, { -34} },         
};

SR__ s_35[] =
{
    { { REQ_DEF}, {   2} },         
    { {     269}, {  54} }, // CLOSE
    { {       0}, { -35} },         
};

SR__ s_36[] =
{
    { { REQ_TOKEN}, {  7} },           
    { {       295}, { 55} }, // a      
    { {       292}, { 19} }, // egesz  
    { {       293}, { 20} }, // valtnum
    { {       268}, { 56} }, // OPEN   
    { {       270}, { 21} }, // AZON   
    { {       267}, { 22} }, // NUMBER 
    { {         0}, {  0} },           
};

SR__ s_37[] =
{
    { { REQ_TOKEN}, {  7} },           
    { {       295}, { 57} }, // a      
    { {       292}, { 19} }, // egesz  
    { {       293}, { 20} }, // valtnum
    { {       268}, { 56} }, // OPEN   
    { {       270}, { 21} }, // AZON   
    { {       267}, { 22} }, // NUMBER 
    { {         0}, {  0} },           
};

SR__ s_38[] =
{
    { { REQ_TOKEN}, {  7} },           
    { {       295}, { 58} }, // a      
    { {       292}, { 19} }, // egesz  
    { {       293}, { 20} }, // valtnum
    { {       268}, { 56} }, // OPEN   
    { {       270}, { 21} }, // AZON   
    { {       267}, { 22} }, // NUMBER 
    { {         0}, {  0} },           
};

SR__ s_39[] =
{
    { { REQ_TOKEN}, {  7} },           
    { {       295}, { 59} }, // a      
    { {       292}, { 19} }, // egesz  
    { {       293}, { 20} }, // valtnum
    { {       268}, { 56} }, // OPEN   
    { {       270}, { 21} }, // AZON   
    { {       267}, { 22} }, // NUMBER 
    { {         0}, {  0} },           
};

SR__ s_40[] =
{
    { { REQ_TOKEN}, {  7} },           
    { {       295}, { 60} }, // a      
    { {       292}, { 19} }, // egesz  
    { {       293}, { 20} }, // valtnum
    { {       268}, { 56} }, // OPEN   
    { {       270}, { 21} }, // AZON   
    { {       267}, { 22} }, // NUMBER 
    { {         0}, {  0} },           
};

SR__ s_41[] =
{
    { { REQ_TOKEN}, {  7} },           
    { {       295}, { 61} }, // a      
    { {       292}, { 19} }, // egesz  
    { {       293}, { 20} }, // valtnum
    { {       268}, { 56} }, // OPEN   
    { {       270}, { 21} }, // AZON   
    { {       267}, { 22} }, // NUMBER 
    { {         0}, {  0} },           
};

SR__ s_42[] =
{
    { { REQ_TOKEN}, {  7} },           
    { {       295}, { 62} }, // a      
    { {       292}, { 19} }, // egesz  
    { {       293}, { 20} }, // valtnum
    { {       268}, { 56} }, // OPEN   
    { {       270}, { 21} }, // AZON   
    { {       267}, { 22} }, // NUMBER 
    { {         0}, {  0} },           
};

SR__ s_43[] =
{
    { { REQ_TOKEN}, {  7} },           
    { {       295}, { 63} }, // a      
    { {       292}, { 19} }, // egesz  
    { {       293}, { 20} }, // valtnum
    { {       268}, { 56} }, // OPEN   
    { {       270}, { 21} }, // AZON   
    { {       267}, { 22} }, // NUMBER 
    { {         0}, {  0} },           
};

SR__ s_44[] =
{
    { { REQ_TOKEN}, {  7} },           
    { {       295}, { 64} }, // a      
    { {       292}, { 19} }, // egesz  
    { {       293}, { 20} }, // valtnum
    { {       268}, { 56} }, // OPEN   
    { {       270}, { 21} }, // AZON   
    { {       267}, { 22} }, // NUMBER 
    { {         0}, {  0} },           
};

SR__ s_45[] =
{
    { { REQ_TOKEN}, {  7} },           
    { {       295}, { 65} }, // a      
    { {       292}, { 19} }, // egesz  
    { {       293}, { 20} }, // valtnum
    { {       268}, { 56} }, // OPEN   
    { {       270}, { 21} }, // AZON   
    { {       267}, { 22} }, // NUMBER 
    { {         0}, {  0} },           
};

SR__ s_46[] =
{
    { { REQ_DEF}, {   3} },       
    { {     282}, {  31} }, // AND
    { {     283}, {  32} }, // OR 
    { {       0}, { -27} },       
};

SR__ s_47[] =
{
    { { REQ_TOKEN}, { 12} },            
    { {       286}, { 66} }, // elements
    { {       287}, {  4} }, // loop    
    { {       288}, {  5} }, // elag    
    { {       289}, {  6} }, // io      
    { {       290}, {  7} }, // erta    
    { {       257}, {  8} }, // END     
    { {       263}, {  9} }, // WHILE   
    { {       259}, { 10} }, // IF      
    { {       266}, { 11} }, // PRINT   
    { {       265}, { 12} }, // INPUT   
    { {       258}, { 13} }, // LET     
    { {         0}, {  0} },            
};

SR__ s_48[] =
{
    { { REQ_TOKEN}, {  7} },           
    { {       292}, { 67} }, // egesz  
    { {       293}, { 68} }, // valtnum
    { {       268}, { 56} }, // OPEN   
    { {       295}, { 69} }, // a      
    { {       270}, { 21} }, // AZON   
    { {       267}, { 22} }, // NUMBER 
    { {         0}, {  0} },           
};

SR__ s_49[] =
{
    { { DEF_RED}, {  1} }, 
    { {       0}, { -9} }, 
};

SR__ s_50[] =
{
    { { REQ_DEF}, {   2} },      
    { {     283}, {  32} }, // OR
    { {       0}, { -25} },      
};

SR__ s_51[] =
{
    { { REQ_DEF}, {   1} }, 
    { {       0}, { -26} }, 
};

SR__ s_52[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -19} }, 
};

SR__ s_53[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -28} }, 
};

SR__ s_54[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -14} }, 
};

SR__ s_55[] =
{
    { { REQ_DEF}, {   1} }, 
    { {       0}, { -20} }, 
};

SR__ s_56[] =
{
    { { REQ_TOKEN}, {  7} },           
    { {       292}, { 34} }, // egesz  
    { {       293}, { 35} }, // valtnum
    { {       268}, { 56} }, // OPEN   
    { {       295}, { 69} }, // a      
    { {       270}, { 21} }, // AZON   
    { {       267}, { 22} }, // NUMBER 
    { {         0}, {  0} },           
};

SR__ s_57[] =
{
    { { REQ_DEF}, {   1} }, 
    { {       0}, { -21} }, 
};

SR__ s_58[] =
{
    { { REQ_DEF}, {   1} }, 
    { {       0}, { -22} }, 
};

SR__ s_59[] =
{
    { { REQ_DEF}, {   1} }, 
    { {       0}, { -23} }, 
};

SR__ s_60[] =
{
    { { REQ_DEF}, {   1} }, 
    { {       0}, { -24} }, 
};

SR__ s_61[] =
{
    { { REQ_DEF}, {   1} }, 
    { {       0}, { -29} }, 
};

SR__ s_62[] =
{
    { { REQ_DEF}, {   1} }, 
    { {       0}, { -30} }, 
};

SR__ s_63[] =
{
    { { REQ_DEF}, {   3} },         
    { {     274}, {  41} }, // PLUS 
    { {     275}, {  42} }, // MINUS
    { {       0}, { -31} },         
};

SR__ s_64[] =
{
    { { REQ_DEF}, {   3} },         
    { {     274}, {  41} }, // PLUS 
    { {     275}, {  42} }, // MINUS
    { {       0}, { -32} },         
};

SR__ s_65[] =
{
    { { REQ_DEF}, {   3} },         
    { {     274}, {  41} }, // PLUS 
    { {     275}, {  42} }, // MINUS
    { {       0}, { -33} },         
};

SR__ s_66[] =
{
    { { REQ_TOKEN}, {  3} },         
    { {       262}, { 70} }, // ENDIF
    { {       261}, { 71} }, // ELSE 
    { {         0}, {  0} },         
};

SR__ s_67[] =
{
    { { REQ_DEF}, {   6} },         
    { {     271}, { -34} }, // MULTI
    { {     272}, { -34} }, // DIV  
    { {     273}, { -34} }, // MOD  
    { {     274}, { -34} }, // PLUS 
    { {     275}, { -34} }, // MINUS
    { {       0}, { -12} },         
};

SR__ s_68[] =
{
    { { REQ_DEF}, {   6} },         
    { {     271}, { -35} }, // MULTI
    { {     272}, { -35} }, // DIV  
    { {     273}, { -35} }, // MOD  
    { {     274}, { -35} }, // PLUS 
    { {     275}, { -35} }, // MINUS
    { {       0}, { -13} },         
};

SR__ s_69[] =
{
    { { REQ_TOKEN}, {  6} },         
    { {       274}, { 41} }, // PLUS 
    { {       275}, { 42} }, // MINUS
    { {       271}, { 43} }, // MULTI
    { {       272}, { 44} }, // DIV  
    { {       273}, { 45} }, // MOD  
    { {         0}, {  0} },         
};

SR__ s_70[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -10} }, 
};

SR__ s_71[] =
{
    { { REQ_TOKEN}, { 12} },            
    { {       286}, { 72} }, // elements
    { {       287}, {  4} }, // loop    
    { {       288}, {  5} }, // elag    
    { {       289}, {  6} }, // io      
    { {       290}, {  7} }, // erta    
    { {       257}, {  8} }, // END     
    { {       263}, {  9} }, // WHILE   
    { {       259}, { 10} }, // IF      
    { {       266}, { 11} }, // PRINT   
    { {       265}, { 12} }, // INPUT   
    { {       258}, { 13} }, // LET     
    { {         0}, {  0} },            
};

SR__ s_72[] =
{
    { { REQ_TOKEN}, {  2} },         
    { {       262}, { 73} }, // ENDIF
    { {         0}, {  0} },         
};

SR__ s_73[] =
{
    { { DEF_RED}, {   1} }, 
    { {       0}, { -11} }, 
};


// State array:
SR__ *s_state[] =
{
  s_0,  s_1,  s_2,  s_3,  s_4,  s_5,  s_6,  s_7,  s_8,  s_9,
  s_10,  s_11,  s_12,  s_13,  s_14,  s_15,  s_16,  s_17,  s_18,  s_19,
  s_20,  s_21,  s_22,  s_23,  s_24,  s_25,  s_26,  s_27,  s_28,  s_29,
  s_30,  s_31,  s_32,  s_33,  s_34,  s_35,  s_36,  s_37,  s_38,  s_39,
  s_40,  s_41,  s_42,  s_43,  s_44,  s_45,  s_46,  s_47,  s_48,  s_49,
  s_50,  s_51,  s_52,  s_53,  s_54,  s_55,  s_56,  s_57,  s_58,  s_59,
  s_60,  s_61,  s_62,  s_63,  s_64,  s_65,  s_66,  s_67,  s_68,  s_69,
  s_70,  s_71,  s_72,  s_73,
};

} // anonymous namespace ends



// If the parsing function call uses arguments, then provide an overloaded
// function.  The code below doesn't rely on parameters, so no arguments are
// required.  Furthermore, parse uses a function try block to allow us to do
// ACCEPT and ABORT from anywhere, even from within members called by actions,
// simply throwing the appropriate exceptions.

ParserBase::ParserBase()
:
    d_stackIdx__(-1),
    // $insert debuginit
    d_debug__(false),
    d_nErrors__(0),
    // $insert requiredtokens
    d_requiredTokens__(0),
    d_acceptedTokens__(d_requiredTokens__),
    d_token__(_UNDETERMINED_),
    d_nextToken__(_UNDETERMINED_)
{}


void Parser::print__()
{
// $insert print
}

void ParserBase::clearin()
{
    d_token__ = d_nextToken__ = _UNDETERMINED_;
}

void ParserBase::push__(size_t state)
{
    if (static_cast<size_t>(d_stackIdx__ + 1) == d_stateStack__.size())
    {
        size_t newSize = d_stackIdx__ + STACK_EXPANSION;
        d_stateStack__.resize(newSize);
        d_valueStack__.resize(newSize);
        // $insert LTYPEresize
        d_locationStack__.resize(newSize);
    }
    ++d_stackIdx__;
    d_stateStack__[d_stackIdx__] = d_state__ = state;
    *(d_vsp__ = &d_valueStack__[d_stackIdx__]) = d_val__;
    // $insert LTYPEpush
    *(d_lsp__ = &d_locationStack__[d_stackIdx__]) = d_loc__;
}

void ParserBase::popToken__()
{
    d_token__ = d_nextToken__;

    d_val__ = d_nextVal__;
    d_nextVal__ = STYPE__();

    d_nextToken__ = _UNDETERMINED_;
}
     
void ParserBase::pushToken__(int token)
{
    d_nextToken__ = d_token__;
    d_nextVal__ = d_val__;
    d_token__ = token;
}
     
void ParserBase::pop__(size_t count)
{
    if (d_stackIdx__ < static_cast<int>(count))
    {
        ABORT();
    }

    d_stackIdx__ -= count;
    d_state__ = d_stateStack__[d_stackIdx__];
    d_vsp__ = &d_valueStack__[d_stackIdx__];
    // $insert LTYPEpop
    d_lsp__ = &d_locationStack__[d_stackIdx__];
}

inline size_t ParserBase::top__() const
{
    return d_stateStack__[d_stackIdx__];
}

void Parser::executeAction(int production)
try
{
    if (d_token__ != _UNDETERMINED_)
        pushToken__(d_token__);     // save an already available token

                                    // save default non-nested block $$
    if (int size = s_productionInfo[production].d_size)
        d_val__ = d_vsp__[1 - size];

    switch (production)
    {
        // $insert actioncases
        
        case 1:
#line 18 "calculate.y"
        {
         std::cout << "start -> expressions" << std::endl;
         }
        break;

        case 2:
#line 25 "calculate.y"
        {
         std::cout << "expressions -> epszilon" << std::endl;
         }
        break;

        case 3:
#line 30 "calculate.y"
        {
         std::cout << "expressions -> elements expressions" << std::endl;
         }
        break;

        case 4:
#line 38 "calculate.y"
        {
         std::cout << "elements -> loop" << std::endl;
         }
        break;

        case 5:
#line 43 "calculate.y"
        { 
         std::cout << "elements -> elag" << std::endl;
         }
        break;

        case 6:
#line 48 "calculate.y"
        {
         std::cout << "elements -> io" << std::endl; 
         }
        break;

        case 7:
#line 53 "calculate.y"
        {
         std::cout << "elements -> erta" << std::endl; 
         }
        break;

        case 8:
#line 58 "calculate.y"
        {
         std::cout << "expressions -> END" << std::endl;
         }
        break;

        case 9:
#line 66 "calculate.y"
        {
         std::cout << "loop -> WHILE logical elements WEND" << std::endl;
         }
        break;

        case 10:
#line 73 "calculate.y"
        {
         std::cout << "elag -> IF logical THEN elements ENDIF" << std::endl;
         }
        break;

        case 11:
#line 78 "calculate.y"
        {
         std::cout << "elag -> IF logical THEN elements ELSE elements ENDIF" << std::endl;
         }
        break;

        case 12:
#line 85 "calculate.y"
        {
         std::cout << "erta -> LET AZON EQ egesz" << std::endl;
         }
        break;

        case 13:
#line 90 "calculate.y"
        {
         std::cout << "erta -> LET AZON EQ valtnum" << std::endl;
         }
        break;

        case 14:
#line 97 "calculate.y"
        {
         std::cout << "valtnum -> OPEN valtnum CLOSE" << std::endl;
         }
        break;

        case 15:
#line 102 "calculate.y"
        {
         std::cout << "valtnum -> AZON" << std::endl;
         }
        break;

        case 16:
#line 107 "calculate.y"
        {
         std::cout << "valtnum -> NUMBER" << std::endl;
         }
        break;

        case 17:
#line 114 "calculate.y"
        {
         std::cout << "kifejezes -> egesz" << std::endl;
         }
        break;

        case 18:
#line 119 "calculate.y"
        {
         std::cout << "kifejezes -> logical" << std::endl;
         }
        break;

        case 19:
#line 126 "calculate.y"
        {
         std::cout << "logical -> OPEN logical CLOSE" << std::endl;
         }
        break;

        case 20:
#line 131 "calculate.y"
        {
         std::cout << "logical -> a EQUAL a" << std::endl;
         }
        break;

        case 21:
#line 136 "calculate.y"
        {
         std::cout << "logical -> a LT a" << std::endl;
         }
        break;

        case 22:
#line 141 "calculate.y"
        {
         std::cout << "logical -> a GT a" << std::endl;
         }
        break;

        case 23:
#line 146 "calculate.y"
        {
         std::cout << "logical -> a LE a" << std::endl;
         }
        break;

        case 24:
#line 151 "calculate.y"
        {
         std::cout << "logical -> a GE a" << std::endl;
         }
        break;

        case 25:
#line 156 "calculate.y"
        {
         std::cout << "logical -> logical AND logical" << std::endl;
         }
        break;

        case 26:
#line 161 "calculate.y"
        {
         std::cout << "logical -> logical OR logical" << std::endl;
         }
        break;

        case 27:
#line 166 "calculate.y"
        {
         std::cout << "logical -> logical NOT logical" << std::endl;
         }
        break;

        case 28:
#line 173 "calculate.y"
        {
         std::cout << "egesz -> OPEN egesz CLOSE" << std::endl;
         }
        break;

        case 29:
#line 178 "calculate.y"
        {
         std::cout << "egesz -> a PLUS a" << std::endl;
         }
        break;

        case 30:
#line 183 "calculate.y"
        {
         std::cout << "egesz -> a MINUS a" << std::endl;
         }
        break;

        case 31:
#line 188 "calculate.y"
        {
         std::cout << "egesz -> a MULTI a" << std::endl;
         }
        break;

        case 32:
#line 193 "calculate.y"
        {
         std::cout << "egesz -> a DIV a" << std::endl;
         }
        break;

        case 33:
#line 198 "calculate.y"
        {
         std::cout << "egesz -> a MOD a" << std::endl;
         }
        break;

        case 34:
#line 205 "calculate.y"
        {
         std::cout << "a -> egesz" << std::endl;
         }
        break;

        case 35:
#line 210 "calculate.y"
        {
         std::cout << "a -> valtnum" << std::endl;
         }
        break;

        case 36:
#line 217 "calculate.y"
        {
         std::cout << "io -> PRINT kifejezes" << std::endl;
         }
        break;

        case 37:
#line 222 "calculate.y"
        {
         std::cout << "io -> PRINT valtnum" << std::endl;
         }
        break;

        case 38:
#line 227 "calculate.y"
        {
         std::cout << "io -> INPUT AZON" << std::endl;
         }
        break;

    }
}
catch (std::exception const &exc)
{
    exceptionHandler__(exc);
}

inline void ParserBase::reduce__(PI__ const &pi)
{
    d_token__ = pi.d_nonTerm;
    pop__(pi.d_size);

}

// If d_token__ is _UNDETERMINED_ then if d_nextToken__ is _UNDETERMINED_ another
// token is obtained from lex(). Then d_nextToken__ is assigned to d_token__.
void Parser::nextToken()
{
    if (d_token__ != _UNDETERMINED_)        // no need for a token: got one
        return;                             // already

    if (d_nextToken__ != _UNDETERMINED_)
    {
        popToken__();                       // consume pending token
    }
    else
    {
        ++d_acceptedTokens__;               // accept another token (see
                                            // errorRecover())
        d_token__ = lex();
        if (d_token__ <= 0)
            d_token__ = _EOF_;
    }
    print();
}

// if the final transition is negative, then we should reduce by the rule
// given by its positive value. Note that the `recovery' parameter is only
// used with the --debug option
int Parser::lookup(bool recovery)
{
    // $insert threading
    SR__ *sr = s_state[d_state__];        // get the appropriate state-table
    int lastIdx = sr->d_lastIdx;        // sentinel-index in the SR__ array

    SR__ *lastElementPtr = sr + lastIdx;
    SR__ *elementPtr = sr + 1;            // start the search at s_xx[1]

    lastElementPtr->d_token = d_token__;// set search-token

    while (elementPtr->d_token != d_token__)
        ++elementPtr;

    if (elementPtr == lastElementPtr)   // reached the last element
    {
        if (elementPtr->d_action < 0)   // default reduction
        {
            return elementPtr->d_action;                
        }

        // No default reduction, so token not found, so error.
        throw UNEXPECTED_TOKEN__;
    }

    // not at the last element: inspect the nature of the action
    // (< 0: reduce, 0: ACCEPT, > 0: shift)

    int action = elementPtr->d_action;


    return action;
}

    // When an error has occurred, pop elements off the stack until the top
    // state has an error-item. If none is found, the default recovery
    // mode (which is to abort) is activated. 
    //
    // If EOF is encountered without being appropriate for the current state,
    // then the error recovery will fall back to the default recovery mode.
    // (i.e., parsing terminates)
void Parser::errorRecovery()
try
{
    if (d_acceptedTokens__ >= d_requiredTokens__)// only generate an error-
    {                                           // message if enough tokens 
        ++d_nErrors__;                          // were accepted. Otherwise
        error("Syntax error");                  // simply skip input

    }


    // get the error state
    while (not (s_state[top__()][0].d_type & ERR_ITEM))
    {
        pop__();
    }

    // In the error state, lookup a token allowing us to proceed.
    // Continuation may be possible following multiple reductions,
    // but eventuall a shift will be used, requiring the retrieval of
    // a terminal token. If a retrieved token doesn't match, the catch below 
    // will ensure the next token is requested in the while(true) block
    // implemented below:

    int lastToken = d_token__;                  // give the unexpected token a
                                                // chance to be processed
                                                // again.

    pushToken__(_error_);                       // specify _error_ as next token
    push__(lookup(true));                       // push the error state

    d_token__ = lastToken;                      // reactivate the unexpected
                                                // token (we're now in an
                                                // ERROR state).

    bool gotToken = true;                       // the next token is a terminal

    while (true)
    {
        try
        {
            if (s_state[d_state__]->d_type & REQ_TOKEN)
            {
                gotToken = d_token__ == _UNDETERMINED_;
                nextToken();                    // obtain next token
            }
            
            int action = lookup(true);

            if (action > 0)                 // push a new state
            {
                push__(action);
                popToken__();

                if (gotToken)
                {

                    d_acceptedTokens__ = 0;
                    return;
                }
            }
            else if (action < 0)
            {
                // no actions executed on recovery but save an already 
                // available token:
                if (d_token__ != _UNDETERMINED_)
                    pushToken__(d_token__);
 
                                            // next token is the rule's LHS
                reduce__(s_productionInfo[-action]); 
            }
            else
                ABORT();                    // abort when accepting during
                                            // error recovery
        }
        catch (...)
        {
            if (d_token__ == _EOF_)
                ABORT();                    // saw inappropriate _EOF_
                      
            popToken__();                   // failing token now skipped
        }
    }
}
catch (ErrorRecovery__)       // This is: DEFAULT_RECOVERY_MODE
{
    ABORT();
}

    // The parsing algorithm:
    // Initially, state 0 is pushed on the stack, and d_token__ as well as
    // d_nextToken__ are initialized to _UNDETERMINED_. 
    //
    // Then, in an eternal loop:
    //
    //  1. If a state does not have REQ_TOKEN no token is assigned to
    //     d_token__. If the state has REQ_TOKEN, nextToken() is called to
    //      determine d_nextToken__ and d_token__ is set to
    //     d_nextToken__. nextToken() will not call lex() unless d_nextToken__ is 
    //     _UNDETERMINED_. 
    //
    //  2. lookup() is called: 
    //     d_token__ is stored in the final element's d_token field of the
    //     state's SR_ array. 
    //
    //  3. The current token is looked up in the state's SR_ array
    //
    //  4. Depending on the result of the lookup() function the next state is
    //     shifted on the parser's stack, a reduction by some rule is applied,
    //     or the parsing function returns ACCEPT(). When a reduction is
    //     called for, any action that may have been defined for that
    //     reduction is executed.
    //
    //  5. An error occurs if d_token__ is not found, and the state has no
    //     default reduction. Error handling was described at the top of this
    //     file.

int Parser::parse()
try 
{
    push__(0);                              // initial state
    clearin();                              // clear the tokens.

    while (true)
    {
        try
        {
            if (s_state[d_state__]->d_type & REQ_TOKEN)
                nextToken();                // obtain next token


            int action = lookup(false);     // lookup d_token__ in d_state__

            if (action > 0)                 // SHIFT: push a new state
            {
                push__(action);
                popToken__();               // token processed
            }
            else if (action < 0)            // REDUCE: execute and pop.
            {
                executeAction(-action);
                                            // next token is the rule's LHS
                reduce__(s_productionInfo[-action]); 
            }
            else 
                ACCEPT();
        }
        catch (ErrorRecovery__)
        {
            errorRecovery();
        }
    }
}
catch (Return__ retValue)
{
    return retValue;
}




