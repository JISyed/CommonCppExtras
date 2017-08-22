#ifndef CCE_CONSTS_HEADER
#define CCE_CONSTS_HEADER

namespace cce
{
	namespace Math
	{
		class Consts
		{
		public:
			
			static const float Pi;
			
		private:

			Consts() = delete;
			~Consts() = delete;
			Consts(const Consts&) = delete;
			Consts& operator=(const Consts&) = delete;
			Consts(Consts&&) = delete;
			Consts& operator=(Consts&&) = delete;

		};
	}
}

#include "Consts.inl"
#endif