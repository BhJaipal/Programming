#ifndef DATA_MODELS
#define DATA_MODELS

namespace MyDSA {
template <typename T> class Model {
  public:
	virtual void push(T data) = 0;
	virtual T pop() = 0;
	virtual void toString() = 0;
};
} // namespace MyDSA

#endif