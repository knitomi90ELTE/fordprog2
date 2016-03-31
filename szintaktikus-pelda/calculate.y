%baseclass-preinclude <iostream>
%lsp-needed

%token END LET IF THEN ELSE ENDIF WHILE WEND INPUT PRINT NUMBER OPEN CLOSE AZON

%left MULTI DIV MOD
%left PLUS MINUS
%left GT LT LE GE
%left EQUAL
%left NOT
%left AND
%left OR

%%

start:
	expressions
	{
		std::cout << "start -> expressions" << std::endl;
	}
;

expressions:
	// ures
	{
		std::cout << "expressions -> epszilon" << std::endl;
	}
|
	elements expressions
	{
		std::cout << "expressions -> elements expressions" << std::endl;
	}

;

elements:
	loop
	{
		std::cout << "elements -> loop" << std::endl;
	}
|
	elag
	{	
		std::cout << "elements -> elag" << std::endl;
	}
|
	io
	{
		std::cout << "elements -> io" << std::endl;	
	}
|
	erta
	{
		std::cout << "elements -> erta" << std::endl;	
	}
|
	END
	{
		std::cout << "expressions -> END" << std::endl;
	}

;

loop:
	WHILE logical elements WEND
	{
		std::cout << "loop -> WHILE logical elements WEND" << std::endl;
	}
;

elag:
	IF logical THEN elements ENDIF
	{
		std::cout << "elag -> IF logical THEN elements ENDIF" << std::endl;
	}
|
	IF logical THEN elements ELSE elements ENDIF
	{
		std::cout << "elag -> IF logical THEN elements ELSE elements ENDIF" << std::endl;
	}
;

erta:
	LET AZON EQUAL egesz
	{
		std::cout << "erta -> LET AZON EQ egesz" << std::endl;
	}
|
	LET AZON EQUAL valtnum
	{
		std::cout << "erta -> LET AZON EQ valtnum" << std::endl;
	}
;

valtnum:
	OPEN valtnum CLOSE
	{
		std::cout << "valtnum -> OPEN valtnum CLOSE" << std::endl;
	}
|
	AZON
	{
		std::cout << "valtnum -> AZON" << std::endl;
	}
|
	NUMBER
	{
		std::cout << "valtnum -> NUMBER" << std::endl;
	}
;

kifejezes:
	egesz
	{
		std::cout << "kifejezes -> egesz" << std::endl;
	}
|
	logical
	{
		std::cout << "kifejezes -> logical" << std::endl;
	}
;

logical:
	OPEN logical CLOSE
	{
		std::cout << "logical -> OPEN logical CLOSE" << std::endl;
	}
|
	a EQUAL a
	{
		std::cout << "logical -> a EQUAL a" << std::endl;
	}
|
	a LT a
	{
		std::cout << "logical -> a LT a" << std::endl;
	}
|
	a GT a
	{
		std::cout << "logical -> a GT a" << std::endl;
	}
|
	a LE a
	{
		std::cout << "logical -> a LE a" << std::endl;
	}
|
	a GE a
	{
		std::cout << "logical -> a GE a" << std::endl;
	}
|
	logical AND logical
	{
		std::cout << "logical -> logical AND logical" << std::endl;
	}
|
	logical OR logical
	{
		std::cout << "logical -> logical OR logical" << std::endl;
	}
|
	NOT logical
	{
		std::cout << "logical -> logical NOT logical" << std::endl;
	}
;

egesz:
	OPEN egesz CLOSE
	{
		std::cout << "egesz -> OPEN egesz CLOSE" << std::endl;
	}
|
	a PLUS a
	{
		std::cout << "egesz -> a PLUS a" << std::endl;
	}
|
	a MINUS a
	{
		std::cout << "egesz -> a MINUS a" << std::endl;
	}
|
	a MULTI a
	{
		std::cout << "egesz -> a MULTI a" << std::endl;
	}
|
	a DIV a
	{
		std::cout << "egesz -> a DIV a" << std::endl;
	}
|
	a MOD a
	{
		std::cout << "egesz -> a MOD a" << std::endl;
	}
;

a:
	egesz
	{
		std::cout << "a -> egesz" << std::endl;
	}
|
	valtnum
	{
		std::cout << "a -> valtnum" << std::endl;
	}
;

io:
	PRINT kifejezes
	{
		std::cout << "io -> PRINT kifejezes" << std::endl;
	}
|
	PRINT valtnum
	{
		std::cout << "io -> PRINT valtnum" << std::endl;
	}
|
	INPUT AZON
	{
		std::cout << "io -> INPUT AZON" << std::endl;
	}
;

