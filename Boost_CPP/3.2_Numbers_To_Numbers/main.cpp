// Converting Numbers to Numbers Using C++ Boost

/*
Converting Numbers to Numbers Using C++ Boost:
	- Here are some examples that we might have coded in the past:

		void some_function(unsigned short);
		int foo();

		void do_something() {
			// some compilers will warn that an int is being converted to an unsigned short, and that there is a possibility
			// that data loss can occur

			some_function(foo());
		}

	- Most programmers will just ignore of the warning, and we just implicitly cast the unsigned short.
	- suppress the warning:
		
		some_function(static_cast<unsigned short>(foo());

	- But what happens if foo() does NOT return an unsigned short? This can lead into very hard detectable erros.
	- Remember above what the function foo() is trying to return, it's trying to return and int, but we attempt to cast it to an
		unsigned short, what happens if that fails?

	- We can use the Boost.NumericConversion can provide a solution for examples like above. We can replace static_cast<> with
		boost::numeric_cast.
	- boost::numeric_cast will throw an exception when the source value cannot be stored in the target.
	- In order to use this we must #include <boost/numeric/conversion/cast.hpp>
	- Ex)

		#include <boost/numeric/conversion/cast.hpp>

		void correct_implementation() {
			some_function(boost::numeric_cast<unsigned short>(foo()));
		}

		void test_function() {
			for (unsigned int i = 0; i < 100; ++i) {
				try {
					correct_implementation();
				} catch (const boost::numeric::bad_numeric_cast &e) {
					std::cout << "#" << i << e.what() << "\n";
				}
			}
		}

	- Now if we run test_function(), it will output the following:

		#47 bad numeric conversion: negative overflow
		#58 bad numeric conversion: positive overflow

	- We can even detct specific overflow types:

		void test_function() {
			for (unsigned int i = 0; i < 100; ++i) {
				try {
					correct_implementation();
				} catch (const boost::numeric::positive_overflow &e) {
					// do something specific for positive overflows
					std::cout << "POS Overflow in #" << i << " " << e.what() << "\n";
				} catch (const boost::numeric::negative_overflow &e) {
					// do something specific for negative overflows
					std::cout << "NEG Overflow in #" << i << " " << e.what() << "\n";
				}
			}
		}

	- boost::numeric_cast checks to see if the value of the input parameter fits into the new type without losing data and throws
		an exception if something is lost during the conversion.
	- The Boost.NumericConversion library has a very fast implementation. Works at compile time.
	- boost::numeric_cast function is implemented vis boost::numeric::converter, which can be tuned to use different overflows,
		range checking, and rounding policies, but usually we just need boost::numeric_cast.
	- Example that shows we can make our own overflow handler for boost::numeric_cast

		template <class Source T, class Target>
		struct may_throw_overflow_handler {
			void operator() (boost::numeric::range_check_result r) {
				if (r != boost::numeric::cInRange) {
					throw std::logic_error("Not in range!");
				}
			}
		};

		template <class TargetT, class SourceT>
		Target my_numeric_cast(const SourceT &in) {
			typedef boost::numeric::conversion_traits<TargetT, SourceT> conv_traits;
			typedef boost::numeric::converter<TargetT, SourceT, conv_traits, may_throw_overflow_handler<SourceT, TargetT>> converter;
		
			return converter::convert(in);
		}

	- Here is how to use the custom converter:

		void example_numeric_cast() {
			short v = 0;
			try {
				v = my_numeric_cast<short>(100000);
			} catch (const std::logic_error &e) {
				std::cout << "it Works! " << e.what() << "\n";
			}
		}

	- Outputs the following: "It Works! Not in range!"
*/


// C++ Includes:
#include <iostream>


int main() {

	return 0;
}
