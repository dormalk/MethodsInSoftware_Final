#pragma once
#include <stdlib.h>
#include "BorderPainter.h"
#include "BorderPainter.h"
#include "SingelBorderPainter.h"
#include "DoubleBorderPainter.h"
#include "NullBorderPainter.h"
#include "Exceptions.h"

enum class BorderType {
	SINGEL,DOUBLE,NONE
};

class BorderFactory {
public:
	static BorderFactory& getInstance() {
		static BorderFactory factory;
		return factory;
	}

	const BorderPainter& getSingel() {
		return _singel;
	}

	const BorderPainter& getDouble() {
		return _double;
	}

	const BorderPainter& getNull() {
		return _null;
	}

	const BorderPainter& getBoarderPainter(BorderType b)
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

	BorderFactory() {};

	//border types
	const SingelBorderPainter _singel;
	const DoubleBorderPainter _double;
	const NullBorderPainter _null;

	//exceptions
	class WrongValue : public Exceptions{
		public:
			const char* massage() const {
				return "wrong border type value";
			};
	};

};


