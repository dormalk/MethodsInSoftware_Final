#pragma once
#include <stdlib.h>
#include "BoarderPainter.h";
#include "BoarderPainter.h";
#include "SingelBoarderPainter.h";
#include "DoubleBoarderPainter.h";
#include "NullBoarderPainter.h";
#include "Exceptions.h";

enum class BorderType {
	SINGEL,DOUBLE,NONE
};

class BorderFactoy {
public:
	static BorderFactoy& getInstance() {
		if (factory == NULL) {
			factory = new BorderFactoy();
		}
		return *factory;
	}

	const BoarderPainter& getSingel() {
		return _singel;
	}

	const BoarderPainter& getDouble() {
		return _double;
	}

	const BoarderPainter& getNull() {
		return _null;
	}

	const BoarderPainter& getBoarderPainter(BorderType b)
	{
		switch (b){
		case BorderType::SINGEL:
			return _singel;
		case BorderType::DOUBLE:
			return _double;
		case BorderType::NONE:
			return _null;
		default:
			throw WrongValue();
		}
	}


private:
	//singelton
	static BorderFactoy* factory;
	
	BorderFactoy() {
		factory = NULL;
	};
	~BorderFactoy() {
		if (factory != NULL)
			delete factory;
	}

	//border types
	const SingelBoarderPainter _singel;
	const DoubleBoarderPainter _double;
	const NullBoarderPainter _null;

	//exceptions
	class WrongValue : public Exceptions{
		public:
			const char* massage() const {
				return "wrong border type value";
			};
	};
};