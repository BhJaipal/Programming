#include "flip-flop.h"

bool sr_flip_flop(bool elec, bool s, bool r, bool qn) {
	if (!(elec & (s | r))) return qn;
	return (s << 1) | r;
}
bool jk_flip_flop(bool elec, bool j, bool k, bool qn) {
	return sr_flip_flop(elec, j & !(qn >> 1), k & !(qn & 1), qn);
}
