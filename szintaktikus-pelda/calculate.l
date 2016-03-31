%option noyywrap c++ yylineno

%{
#include "Parserbase.h"
%}

DIGIT       [0-9]
WS	    [ \t\n]
BETU        [a-zA-Z]

%%

END         return Parser::END;
LET         return Parser::LET;
IF          return Parser::IF;
THEN        return Parser::THEN;
ELSE        return Parser::ELSE;
ENDIF       return Parser::ENDIF;
WHILE       return Parser::WHILE;
WEND        return Parser::WEND;
INPUT       return Parser::INPUT;
PRINT       return Parser::PRINT;
"="         return Parser::EQUAL;
"<"         return Parser::LT;
">"         return Parser::GT;
"<="        return Parser::LE;
">="        return Parser::GE;
"+"         return Parser::PLUS;
"-"         return Parser::MINUS;
"*"         return Parser::MULTI;
AND         return Parser::AND;
OR          return Parser::OR;
NOT         return Parser::NOT;
"\\"        return Parser::DIV;
MOD         return Parser::MOD;
"("         return Parser::OPEN;
")"         return Parser::CLOSE;

0|([1-9][0-9]*) return Parser::NUMBER;

{BETU}({BETU}|{DIGIT})*"&"    return Parser::AZON;

REM.*\n     // megjegyzes: nem kell semmit csinalni

{WS}+       // feher szokozok: semmi teendo

.           {
                std::cerr << lineno() << ": Lexikalis hiba." << std::endl;
                exit(1);
            }

%%
