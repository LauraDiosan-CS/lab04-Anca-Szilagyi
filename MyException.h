#pragma once
class MyException {
protected:
	const char* message;
public:
	MyException(const char* m) : message(m) {
	}
	const char* getMessage() {
		return message;
	}
};
