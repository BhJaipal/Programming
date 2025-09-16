#ifndef FLIPFLOP_H
#define FLIPFLOP_H
#if !__cplusplus
typedef char bool;
#endif

bool sr_flip_flop(bool elec, bool s, bool r, bool qn);
#define delay_flip_flop(elec, delay, qn) sr_flip_flop(elec, delay, !delay, qn)
bool jk_flip_flop(bool elec, bool j, bool k, bool qn);
#define toggle_flip_flop(elec, toggle, qn) jk_flip_flop(elec, toggle, toggle, qn)

#endif // !FLIPFLOP_H
