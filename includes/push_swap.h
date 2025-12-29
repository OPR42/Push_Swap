/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opr <opr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:12:56 by orobert           #+#    #+#             */
/*   Updated: 2025/12/15 20:14:38 by opr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# define DELAY 1000000UL

typedef struct s_stack
{
	struct s_stack	*previous;
	struct s_stack	*next;
	struct s_stack	*target;
	int				value;
	unsigned int	rank;
	unsigned int	target_cost;
	int				dist_top;
	short			keep;
}	t_stack;

typedef struct s_char
{
	uint32_t		c;
	unsigned char	color;
	short			pass;
}	t_char;

typedef struct s_data
{
	struct s_stack	*stack_a_hook;
	struct s_stack	*stack_b_hook;
	struct s_stack	*stack_a_curr;
	struct s_stack	*stack_b_curr;
	short			algo_type;
	char			*algo_class;
	char			*algo_name;
	short			bench_mode;
	unsigned int	count_nb;
	unsigned int	count_nb_a;
	unsigned int	count_nb_b;
	int				initial_mess;
	float			initial_disorder;
	float			current_disorder;
	unsigned int	count_ops;
	unsigned int	count_changes;
	unsigned int	count_moves;
	unsigned int	count_sa;
	unsigned int	count_sb;
	unsigned int	count_ss;
	unsigned int	count_pa;
	unsigned int	count_pb;
	unsigned int	count_ra;
	unsigned int	count_rb;
	unsigned int	count_rr;
	unsigned int	count_rra;
	unsigned int	count_rrb;
	unsigned int	count_rrr;
	int				max_progress;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	last_swap;
	unsigned int	range;
	short			way;
	short			swapped;
	unsigned int	n;
	unsigned int	chunk_size;
	unsigned int	high;
	unsigned int	effective_high;
	unsigned int	rank;
	unsigned short	order[46];
	t_char			display[50][80];
}	t_data;

typedef unsigned int	t_uint;

int			ps_intlen(int n);
long long	ps_atolli(const char *nptr);
int			ps_isint(const char *nptr);
size_t		ps_strlen(const char *s);
int			ps_strncmp(const char *s1, const char *s2, size_t n);
char		*ps_strdup(const char *s);
char		**ps_split(char const *s, char c);
void		ps_free_all(char **tab, size_t j);
int			ps_init_stacks(t_data *data);
void		ps_stack_clear(t_stack *hook);
int			send_nodes(t_data *data, int value);
void		ps_set_ranks(t_data *data, unsigned int i, unsigned int j);
int			ps_stack_not_progressive(t_stack *hook);
float		ps_compute_disorder(t_data *data);
void		ps_algochoice(t_data *data);
int			ps_sorting_done(t_data *data, t_stack *hka, t_stack *hkb);
void		ps_wait(int interval);
void		ps_exec(t_data *data, char *instruction, unsigned int quantity);
void		ps_sa(t_data *data, short alone);
void		ps_sb(t_data *data, short alone);
void		ps_ss(t_data *data);
void		ps_pa(t_data *data);
void		ps_pb(t_data *data);
void		ps_ra(t_data *data, short alone);
void		ps_rb(t_data *data, short alone);
void		ps_rr(t_data *data);
void		ps_rra(t_data *data, short alone);
void		ps_rrb(t_data *data, short alone);
void		ps_rrr(t_data *data);
void		ps_algo_none(t_data *data);
void		ps_algo_simple(t_data *data);
void		ps_algo_medium(t_data *data);
void		ps_algo_complex(t_data *data);
void		ps_algo_custom_simple(t_data *data);
void		ps_algo_custom_medium(t_data *data);
void		ps_algo_custom_complex(t_data *data);
void		ps_algo_adaptive(t_data *data);
void		sort_three(t_data *data, t_stack *hook);
void		sort_five(t_data *data, t_stack *ha, t_stack *hb);
void		cocktail_shaker(t_data *data);
void		dynamic_chunk(t_data *data, t_stack *hka, t_stack *hkb, t_uint low);
void		radix2(t_data *data, t_stack *hk, t_uint n, t_uint mask);
void		yavuz_sultan(t_data *data, t_stack *hka, t_stack *hkb, t_uint keep);
void		ps_simple_bouncer(t_data *data, t_stack *hka);
void		ps_chunk_harvest(t_data *data, t_stack *hka, t_uint low, t_uint kp);
void		ps_display_bench(t_data *data);
void		ps_count_changes_moves(t_data *data);
void		ps_put_bench_nbr(t_data *data, int n, int x, int y);
void		ps_put_algo(t_data *data, const char *algo, int x, int y);
void		ps_init_banner(t_data *data);
void		ps_scroll_banner(t_data *data, int x, int y);
void		ps_display_benchview(t_data *data, int step);
void		ps_print_canvas(t_data *data, char color, int x, int y);
void		ps_put_stacks(t_data *data, unsigned int y, unsigned int x);
void		ps_show_ballance_level(t_data *data, unsigned int x);
void		ps_put_char_xy(t_data *data, char c, int xy, char color);
void		ps_paint12cells(t_data *data, int x, int y, char color);
void		ps_put_spaces(t_data *data, int x, int x_end, int y);
void		ps_put_nbr_cent(t_data *data, int n, int xy, char color);
void		ps_put_separator(t_data *data, int x, unsigned int count);
void		ps_put_progress(t_data *data, long done, long mess, int x);
void		ps_huge_success(t_data *data);
void		ps_paint_zone_up(t_data *data, char ca, char cb, char cc);
void		ps_paint_zone_down(t_data *data, char ca, char cb);
void		ps_put_panel(t_data *data, const char *panel);
char		*ps_read_element(t_data *data, int x, int y);
void		ps_write_element(t_data *data, int x, int y, char *str);
void		ps_anim_choose(t_data *data, int step);
void		ps_anim_sa(t_data *data);
void		ps_anim_sb(t_data *data);
void		ps_anim_ss(t_data *data);
void		ps_anim_sx_colors(t_data *data, short op, int frame);
void		ps_anim_separator_opener(t_data *data, int pos, int step);
void		ps_anim_pa(t_data *data);
void		ps_anim_pa_a_down(t_data *data, int frame);
void		ps_anim_pa_b_up(t_data *data, int frame);
void		ps_anim_pb(t_data *data);
void		ps_anim_pb_a_up(t_data *data, int frame);
void		ps_anim_pb_b_down(t_data *data, int frame);
void		ps_anim_ra(t_data *data);
void		ps_anim_ra_loop(t_data *data, int frm, int l, char *frst);
void		ps_anim_ra_longloop(t_data *data, int frame, int len, char *up);
void		ps_anim_rb(t_data *data);
void		ps_anim_rr(t_data *data);
void		ps_anim_rb_loop(t_data *data, int frm, int l, char *frst);
void		ps_anim_rb_longloop(t_data *data, int frame, int len, char *up);
void		ps_anim_rr(t_data *data);
void		ps_anim_rx_colors(t_data *data, short op, int frame);
void		ps_anim_rra(t_data *data);
void		ps_anim_rra_loop(t_data *data, int frm, int l, char *lst);
void		ps_anim_rra_longloop(t_data *data, int frame, int len, char *down);
void		ps_anim_rrb(t_data *data);
void		ps_anim_rrb_loop(t_data *data, int frm, int l, char *lst);
void		ps_anim_rrb_longloop(t_data *data, int frame, int len, char *down);
void		ps_anim_rrr(t_data *data);
void		ps_stacks_rotate(t_data *data, int rot_a, int rot_b);
int			ps_send_recon(t_stack *hook);
int			ps_is_target(t_stack *a, t_stack *b, t_stack *hook);
void		ps_stack_align_min_to_top(t_data *data, t_stack *hook);
t_uint		ps_calc_chunk_size(unsigned int n, float disorder);
void		ps_sort_three(t_data *data, t_stack *hook);
t_uint		ps_abs(int signed_value);
t_uint		ps_rot_cost(int rot_a, int rot_b);
t_uint		ps_mark_longest_grow(t_stack *hook);
void		ps_mark_distances_to_top(t_data *data);
void		ps_mark_cost_to_target(t_data *data, t_stack *hk_b, t_stack *hk_a);
int			ps_utf8_encode(uint32_t cp, unsigned char out[4]);
uint32_t	ps_utf8_next(const char **s, uint32_t cp);
int			ps_utf8_strlen(const char *s);
void		ps_forward_utf8_string(const char **s, unsigned int steps);
void		ps_write_unicode(int fd, uint32_t cp);
void		ps_put_large_numbers(t_data *data);

# define BENCH "\
                                                                               \
 ╔════════════════════════════════════════════════════════════════════════════╗\
 ║  ◢◤ ◤█       ▁▁▁▁             ▁▁         ▁▁▁▁▁                      █◥ ◥◣  ║\
 ║ ◢◤  ◢◤      ╱ ▁▁ ╲▁▁  ▁▁▁▁▁▁▁╱ ╱▁       ╱ ▁▁▁╱      ▁▁▁▁▁▁▁▁▁▁▁▁    ◥◣  ◥◣ ║\
 ║ ███ █◢     ╱ ╱▁╱ ╱ ╱ ╱ ╱ ▁▁▁╱ ▁▁ ╲      ╲▁▁ ╲ │ ╱│ ╱ ╱ ▁▁  ╱ ▁▁ ╲   ◣█ ███ ║\
 ║   █       ╱ ▁▁▁▁╱ ╱▁╱ ❬▁▁  ╱ ╱ ╱ ╱     ▁▁▁╱ ╱ │╱ │╱ ╱ ╱▁╱ ╱ ╱▁╱ ╱      █   ║\
 ║  2025    ╱▁╱    ╲▁▁▁▁╱▁▁▁▁╱▁╱ ╱▁╱▁▁▁▁▁╱▁▁▁▁╱│▁▁╱│▁▁╱╲▁▁▁▁╱ ▁▁▁▁╱     2025  ║\
 ║                                ╱▁▁▁▁▁▁╱                 ╱▁╱                ║\
 ║                                                                            ║\
 ║  OPR                   42 - orobert & jreibel - 2025                 Shaco ║\
 ╠═════════════════════════════════════╤══════════════════════════════════════╣\
 ║  Elements.........................  │  Initial disorder..................  ║\
 ║  Operations.......................  │  Strategy class....................  ║\
 ╟───────────────────────┬─────────────┴─────────────┬────────────────────────╢\
 ║  Changes............  │ ......................... │  Moves...............  ║\
 ╟──────────────────┬────┴─────────────┬─────────────┴────┬───────────────────╢\
 ║  sa............  │  pa............  │  ra............  │  rra............  ║\
 ║  sb............  │  pb............  │  rb............  │  rrb............  ║\
 ║  ss............  │                  │  rr............  │  rrr............  ║\
 ╚══════════════════╧══════════════════╧══════════════════╧═══════════════════╝\
                                                                               \
"
# define COLORBENCH "\
00000000000000000000000000000000000000000000000000000000000000000000000000000000\
03333333333333333333333333333333333333333333333333333333333333333333333333333330\
03000000055555555555555555555555555555555555555555555555555555555555555000000030\
03000000055555555555555555555555555555555555555555555555555555555555555000000030\
03000000055555555555555555555555555555555555555555555555555555555555555000000030\
03000000055555555555555555555555555555555555555555555555555555555555555000000030\
03000000055555555555555555555555555555555555555555555555555555555555555000000030\
03000000055555555555555555555555555555555555555555555555555555555555555000000030\
03000000000000000000000000000000000000000000000000000000000000000000000000000030\
03000000000000000000000000660305555555030555555503066660000000000000000000000030\
03333333333333333333333333333333333333333333333333333333333333333333333333333330\
03007777777777777777777777777777777770030077777777777777777777777777777777770030\
03007777777777777777777777777777777770030077777777777777777777777777777777770030\
03333333333333333333333333333333333333333333333333333333333333333333333333333330\
03007777777777777777777003555555555555555555555555555300777777777777777777770030\
03333333333333333333333333333333333333333333333333333333333333333333333333333330\
03007777777777777700300777777777777770030077777777777777003007777777777777770030\
03007777777777777700300777777777777770030077777777777777003007777777777777770030\
03007777777777777700300000000000000000030077777777777777003007777777777777770030\
03333333333333333333333333333333333333333333333333333333333333333333333333333330\
00000000000000000000000000000000000000000000000000000000000000000000000000000000\
"
# define BENCHVIEW "\
                                                                               \
 ╔════════════════════════════════════════════════════════════════════════════╗\
 ║  ◢◤ ◤█       ▁▁▁▁             ▁▁         ▁▁▁▁▁                      █◥ ◥◣  ║\
 ║ ◢◤  ◢◤      ╱ ▁▁ ╲▁▁  ▁▁▁▁▁▁▁╱ ╱▁       ╱ ▁▁▁╱      ▁▁▁▁▁▁▁▁▁▁▁▁    ◥◣  ◥◣ ║\
 ║ ███ █◢     ╱ ╱▁╱ ╱ ╱ ╱ ╱ ▁▁▁╱ ▁▁ ╲      ╲▁▁ ╲ │ ╱│ ╱ ╱ ▁▁  ╱ ▁▁ ╲   ◣█ ███ ║\
 ║   █       ╱ ▁▁▁▁╱ ╱▁╱ ❬▁▁  ╱ ╱ ╱ ╱     ▁▁▁╱ ╱ │╱ │╱ ╱ ╱▁╱ ╱ ╱▁╱ ╱      █   ║\
 ║  2025    ╱▁╱    ╲▁▁▁▁╱▁▁▁▁╱▁╱ ╱▁╱▁▁▁▁▁╱▁▁▁▁╱│▁▁╱│▁▁╱╲▁▁▁▁╱ ▁▁▁▁╱     2025  ║\
 ║                                ╱▁▁▁▁▁▁╱                 ╱▁╱                ║\
 ║                                                                            ║\
 ║  OPR                   42 - orobert & jreibel - 2025                 Shaco ║\
 ╠═══════════════╤═════╤═══╤════════════════════════╤═══╤═════╤═══════════════╣\
 ║╱╱         ╲╲╭─┴─────┴─╮ │  ⚒  ⚙   .....%  ⚙  ⚒   │ ╭─┴─────┴─╮╱╱         ╲╲║\
 ║█           █┤ Stack A ├─┼────────────────────────┼─┤ Stack B ├█           █║\
 ║╲╲         ╱╱╰────▾────╯ ╰───────○╶──○╶──○╶───────╯ ╰────▾────╯╲╲         ╱╱║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║             ...........                            ...........             ║\
 ║                         ╭────────────────────────╮                         ║\
 ╠═════════════════════════╧═══════════╤════════════╧═════════════════════════╣\
 ║  Elements.........................  │  Initial disorder..................  ║\
 ║  Operations.......................  │  Strategy class....................  ║\
 ╟───────────────────────┬─────────────┴─────────────┬────────────────────────╢\
 ║  Changes............  │ ......................... │  Moves...............  ║\
 ╟──────────────────┬────┴─────────────┬─────────────┴────┬───────────────────╢\
 ║  sa............  │  pa............  │  ra............  │  rra............  ║\
 ║  sb............  │  pb............  │  rb............  │  rrb............  ║\
 ║  ss............  │                  │  rr............  │  rrr............  ║\
 ╚══════════════════╧══════════════════╧══════════════════╧═══════════════════╝\
                                                                               \
"
# define COLORBENCHVIEW "\
00000000000000000000000000000000000000000000000000000000000000000000000000000000\
03333333333333333333333333333333333333333333333333333333333333333333333333333330\
03000000000000005555554444446666677777770000777770000000000000000000000000000030\
03000000000000055555544444466666777777700007777770000006644444455550000000000030\
03000000000000555555444444666667777777000007777776666666644444455555000000000030\
03000000000005555554444446666677777770000077777766666666444444555555000000000030\
03000000000055555544444466666777777755555777777666666664444445555550000000000030\
03000000000000000000000000000000005555555500000000000000000555000000000000000030\
03000000000000000000000000000000000000000000000000000000000000000000000000000030\
03000000000000000000000000660305555555030555555503066660000000000000000000000030\
03333333333333333333333333333333333333333333333333333333333333333333333333333330\
03333333333333333333333333030555555506666660555555503033333333333333333333333330\
03333333333333330777777703333333333333333333333333333330777777703333333333333330\
03333333333333333333533333033333333533353335333333333033333533333333333333333330\
03066666666666077777777777000000000000000000000000000077777777777066666666666030\
03066666666666077777777777000000000000000000000000000077777777777066666666666030\
03066666666666077777777777007777777777777777777777770077777777777066666666666030\
03066666666666077777777777007777777777777777777777770077777777777066666666666030\
03066666666666077777777777007777777777777777777777770077777777777066666666666030\
03066666666666077777777777066666666666666666666666666077777777777066666666666030\
03066666666666077777777777066666666666666666666666666077777777777066666666666030\
03066666666666077777777777066666666666666666666666666077777777777066666666666030\
03066666666666077777777777066666666666666666666666666077777777777066666666666030\
03066666666666077777777777066666666666666666666666666077777777777066666666666030\
03066666666666077777777777066666666666666666666666666077777777777066666666666030\
03066666666666777777777777766666666666666666666666666777777777777766666666666030\
03066666666666077777777777066666666666666666666666666077777777777066666666666030\
03066666666666077777777777066666666666666666666666666077777777777066666666666030\
03066666666666077777777777066666666666666666666666666077777777777066666666666030\
03066666666666077777777777066666666666666666666666666077777777777066666666666030\
03066666666666077777777777066666666666666666666666666077777777777066666666666030\
03066666666666077777777777066666666666666666666666666077777777777066666666666030\
03066666666666077777777777066666666666666666666666666077777777777066666666666030\
03066666666666077777777777066666666666666666666666666077777777777066666666666030\
03066666666666077777777777066666666666666666666666666077777777777066666666666030\
03066666666666077777777777066666666666666666666666666077777777777066666666666030\
03066666666666077777777777066666666666666666666666666077777777777066666666666030\
03066666666666077777777777000000000000000000000000000077777777777066666666666030\
03066666666666666666666666033333333333333333333333333066666666666666666666666030\
03333333333333333333333333333333333333333333333333333333333333333333333333333330\
03007777777777777777777777777777777770030077777777777777777777777777777777770030\
03007777777777777777777777777777777770030077777777777777777777777777777777770030\
03333333333333333333333333333333333333333333333333333333333333333333333333333330\
03007777777777777777777003555555555555555555555555555300777777777777777777770030\
03333333333333333333333333333333333333333333333333333333333333333333333333333330\
03007777777777777700300777777777777770030077777777777777003007777777777777770030\
03007777777777777700300777777777777770030077777777777777003007777777777777770030\
03007777777777777700300000000000000000030077777777777777003007777777777777770030\
03333333333333333333333333333333333333333333333333333333333333333333333333333330\
00000000000000000000000000000000000000000000000000000000000000000000000000000000\
"
# define LARGEDIGITS "\
┏━┓╺┓ ┏━┓┏━┓╻ ╻┏━╸┏━┓┏━┓┏━┓┏━┓\
┃ ┃ ┃ ┏━┛ ╺┫┗━┫┗━┓┣━┓  ┃┣━┫┗━┫\
┗━┛╺┻╸┗━╸┗━┛  ╹┗━┛┗━┛  ╹┗━┛┗━┛\
"
# define INCREASEBARS " ▁▂▃▄▅▆▇█"
# define SEPARATOR "\
     ╱ ╲     \
╱▔▔▔▔   ▔▔▔▔╲\
┆           ┆\
╲▁▁▁▁   ▁▁▁▁╱\
     ╲ ╱     \
"
# define SUCCESS "\
       operations       \
             ▁          \
            │)╲         \
            :  )        \
   ▁▁  ▁   ╱  ╱▁▁▁▁     \
     ││G│-`  '(▁▁▁▁)    \
     ││O│     (▁▁▁▁▁)   \
     ││O│     (▁▁▁▁)    \
   ☻ ││D│-.▁▁▁(▁▁▁)     \
   ━━╵ ▔                \
       Well done!       \
                        \
                        \
                        \
                        \
                        \
                        \
                        \
                        \
"
# define FAIL "\
   wasted  operations   \
   ▁▁  ▁   ▁▁▁▁▁▁       \
     ││l│-'     ▁)      \
     ││o│        ▁)     \
     ││s│        ▁▁)    \
   ☹ ││t│-.   ▁▁▁▁)     \
   ━━╵ ▔   ╲  ╲         \
            :  )        \
            │)╱         \
             ▔          \
  We've all been there  \
                        \
                        \
                        \
                        \
                        \
                        \
                        \
                        \
"
# define PANELSA "\
                        \
     ▁▁▁▁▁     ▁▁▁      \
    ╱ ▁▁▁▁▎   ╱   ╲     \
    ╲ ╲▁▁▁   ╱ ╱▔╲ ╲    \
     ╲▁▁▁ ╲  ▎ ▔▔▔ ▕    \
    ╱╲▁▁╱ ╱  ▎▕▔▔▔▎▕    \
    ╲▁▁▁▁╱   ╲▕   ▎╱    \
     ▁▁▁      ▔   ▔     \
    ╱ ▁ ╲               \
    ╲▁▁▁╱╲              \
 ╱        ╲             \
 ╲  ▁▁▁   ╱             \
  ╲╱ ▁ ╲                \
   ╲▁▁▁╱                \
                        \
                        \
                        \
                        \
                        \
"
# define PANELSB "\
                        \
     ▁▁▁▁▁   ▁▁▁▁▁▁     \
    ╱ ▁▁▁▁▎  ▎ ▁▁▁ ╲    \
    ╲ ╲▁▁▁   ▎▕▁▁╱ ╱    \
     ╲▁▁▁ ╲  ▎ ▁▁▁ ╲    \
    ╱╲▁▁╱ ╱  ▎▕▁▁╱ ╱    \
    ╲▁▁▁▁╱   ╲▁▁▁▁╱     \
                ▁▁▁     \
               ╱ ▁ ╲    \
              ╱╲▁▁▁╱    \
             ╱        ╲ \
             ╲   ▁▁▁  ╱ \
                ╱ ▁ ╲╱  \
                ╲▁▁▁╱   \
                        \
                        \
                        \
                        \
                        \
"
# define PANELSS "\
                        \
     ▁▁▁▁▁    ▁▁▁▁▁     \
    ╱ ▁▁▁▁▎  ╱ ▁▁▁▁▎    \
    ╲ ╲▁▁▁   ╲ ╲▁▁▁     \
     ╲▁▁▁ ╲   ╲▁▁▁ ╲    \
    ╱╲▁▁╱ ╱  ╱╲▁▁╱ ╱    \
    ╲▁▁▁▁╱   ╲▁▁▁▁╱     \
     ▁▁▁        ▁▁▁     \
    ╱ ▁ ╲      ╱ ▁ ╲    \
    ╲▁▁▁╱╲    ╱╲▁▁▁╱    \
 ╱        ╲  ╱        ╲ \
 ╲  ▁▁▁   ╱  ╲   ▁▁▁  ╱ \
  ╲╱ ▁ ╲        ╱ ▁ ╲╱  \
   ╲▁▁▁╱        ╲▁▁▁╱   \
                        \
                        \
                        \
                        \
                        \
"
# define PANELPA "\
                        \
    ▁▁▁▁▁▁     ▁▁▁      \
    ▎ ▁▁▁ ╲   ╱   ╲     \
    ▎▕▁▁╱ ╱  ╱ ╱▔╲ ╲    \
    ▎ ▁▁▁╱   ▎ ▔▔▔ ▕    \
    ▎ ▎      ▎▕▔▔▔▎▕    \
    ╲▁▎      ╲▕   ▎╱    \
              ▔   ▔     \
    ╱▎               ╱▎ \
   ╱ ▎              ╱ ▎ \
  ╱  ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔ ╱  \
  ╲  ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁ ╲  \
   ╲ ▎              ╲ ▎ \
    ╲▎               ╲▎ \
                        \
                        \
                        \
                        \
                        \
"
# define PANELPB "\
                        \
    ▁▁▁▁▁▁   ▁▁▁▁▁▁     \
    ▎ ▁▁▁ ╲  ▎ ▁▁▁ ╲    \
    ▎▕▁▁╱ ╱  ▎▕▁▁╱ ╱    \
    ▎ ▁▁▁╱   ▎ ▁▁▁ ╲    \
    ▎ ▎      ▎▕▁▁╱ ╱    \
    ╲▁▎      ╲▁▁▁▁╱     \
                        \
 ▕╲               ▕╲    \
 ▕ ╲              ▕ ╲   \
  ╲ ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔  ╲  \
  ╱ ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁  ╱  \
 ▕ ╱              ▕ ╱   \
 ▕╱               ▕╱    \
                        \
                        \
                        \
                        \
                        \
"
# define PANELRA "\
                        \
    ▁▁▁▁▁▁     ▁▁▁      \
    ▎ ▁▁▁ ╲   ╱   ╲     \
    ▎▕▁▁╱ ╱  ╱ ╱▔╲ ╲    \
    ▎ ▁  ╱   ▎ ▔▔▔ ▕    \
    ▎ ▎╲ ╲   ▎▕▔▔▔▎▕    \
    ╲ ▎ ╲ ▎  ╲▕   ▎╱    \
     ▔   ▔    ▔   ▔     \
    ╱╲                  \
   ╱  ╲                 \
  ╱    ╲                \
 ╱      ╲               \
 ▔▔▎  ▕▔▔               \
   ▎  ▕                 \
   ▎  ▕                 \
   ▎  ▕                 \
  ╱    ╲                \
 ╱  ╱╲  ╲               \
 ▔▔▔  ▔▔▔               \
"
# define PANELRB "\
                        \
    ▁▁▁▁▁▁   ▁▁▁▁▁▁     \
    ▎ ▁▁▁ ╲  ▎ ▁▁▁ ╲    \
    ▎▕▁▁╱ ╱  ▎▕▁▁╱ ╱    \
    ▎ ▁  ╱   ▎ ▁▁▁ ╲    \
    ▎ ▎╲ ╲   ▎▕▁▁╱ ╱    \
    ╲ ▎ ╲ ▎  ╲    ╱     \
     ▔   ▔    ▔▔▔▔      \
                  ╱╲    \
                 ╱  ╲   \
                ╱    ╲  \
               ╱      ╲ \
               ▔▔▎  ▕▔▔ \
                 ▎  ▕   \
                 ▎  ▕   \
                 ▎  ▕   \
                ╱    ╲  \
               ╱  ╱╲  ╲ \
               ▔▔▔  ▔▔▔ \
"
# define PANELRR "\
                        \
    ▁▁▁▁▁▁   ▁▁▁▁▁▁     \
    ▎ ▁▁▁ ╲  ▎ ▁▁▁ ╲    \
    ▎▕▁▁╱ ╱  ▎▕▁▁╱ ╱    \
    ▎ ▁  ╱   ▎ ▁  ╱     \
    ▎ ▎╲ ╲   ▎ ▎╲ ╲     \
    ╲ ▎ ╲ ▎  ╲ ▎ ╲ ▎    \
     ▔   ▔    ▔   ▔     \
    ╱╲            ╱╲    \
   ╱  ╲          ╱  ╲   \
  ╱    ╲        ╱    ╲  \
 ╱      ╲      ╱      ╲ \
 ▔▔▎  ▕▔▔      ▔▔▎  ▕▔▔ \
   ▎  ▕          ▎  ▕   \
   ▎  ▕          ▎  ▕   \
   ▎  ▕          ▎  ▕   \
  ╱    ╲        ╱    ╲  \
 ╱  ╱╲  ╲      ╱  ╱╲  ╲ \
 ▔▔▔  ▔▔▔      ▔▔▔  ▔▔▔ \
"
# define PANELRRA "\
                        \
▁▁▁▁▁▁   ▁▁▁▁▁▁    ▁▁▁  \
▎ ▁▁▁ ╲  ▎ ▁▁▁ ╲  ╱   ╲ \
▎▕▁▁╱ ╱  ▎▕▁▁╱ ╱ ╱ ╱▔╲ ╲\
▎ ▁  ╱   ▎ ▁  ╱  ▎ ▔▔▔ ▕\
▎ ▎╲ ╲   ▎ ▎╲ ╲  ▎▕▔▔▔▎▕\
╲▁▎ ╲ ▎  ╲ ▎ ╲ ▎ ╲▕   ▎╱\
 ▁▁▁ ▔▁▁▁ ▔   ▔   ▔   ▔ \
 ╲  ╲╱  ╱               \
  ╲    ╱                \
   ▎  ▕                 \
   ▎  ▕                 \
   ▎  ▕                 \
 ▁▁▎  ▕▁▁               \
 ╲      ╱               \
  ╲    ╱                \
   ╲  ╱                 \
    ╲╱                  \
                        \
"
# define PANELRRB "\
                        \
▁▁▁▁▁▁   ▁▁▁▁▁▁  ▁▁▁▁▁▁ \
▎ ▁▁▁ ╲  ▎ ▁▁▁ ╲ ▎ ▁▁▁ ╲\
▎▕▁▁╱ ╱  ▎▕▁▁╱ ╱ ▎▕▁▁╱ ╱\
▎ ▁  ╱   ▎ ▁  ╱  ▎ ▁▁▁ ╲\
▎ ▎╲ ╲   ▎ ▎╲ ╲  ▎▕▁▁╱ ╱\
╲ ▎ ╲ ▎  ╲ ▎ ╲ ▎ ╲▁▁▁▁╱ \
 ▔   ▔    ▔   ▔▁▁▁  ▁▁▁ \
               ╲  ╲╱  ╱ \
                ╲    ╱  \
                 ▎  ▕   \
                 ▎  ▕   \
                 ▎  ▕   \
               ▁▁▎  ▕▁▁ \
               ╲      ╱ \
                ╲    ╱  \
                 ╲  ╱   \
                  ╲╱    \
                        \
"
# define PANELRRR "\
                        \
▁▁▁▁▁▁   ▁▁▁▁▁▁  ▁▁▁▁▁▁ \
▎ ▁▁▁ ╲  ▎ ▁▁▁ ╲ ▎ ▁▁▁ ╲\
▎▕▁▁╱ ╱  ▎▕▁▁╱ ╱ ▎▕▁▁╱ ╱\
▎ ▁  ╱   ▎ ▁  ╱  ▎ ▁  ╱ \
▎ ▎╲ ╲   ▎ ▎╲ ╲  ▎ ▎╲ ╲ \
╲▁▎ ╲▁▎  ╲ ▎ ╲ ▎ ╲▁▎ ╲▁▎\
 ▁▁▁  ▁▁▁ ▔   ▔▁▁▁  ▁▁▁ \
 ╲  ╲╱  ╱      ╲  ╲╱  ╱ \
  ╲    ╱        ╲    ╱  \
   ▎  ▕          ▎  ▕   \
   ▎  ▕          ▎  ▕   \
   ▎  ▕          ▎  ▕   \
 ▁▁▎  ▕▁▁      ▁▁▎  ▕▁▁ \
 ╲      ╱      ╲      ╱ \
  ╲    ╱        ╲    ╱  \
   ╲  ╱          ╲  ╱   \
    ╲╱            ╲╱    \
                        \
"
# define AWESOME "\
╔══════════════════════════╗\
║  ☄  ✯ ╻ ╻╻ ╻┏━╸┏━╸ ✴  ✫  ║\
║   ✫   ┣━┫┃ ┃┃╺┓┣╸   ★  ✬ ║\
║ ★  ✴  ╹ ╹┗━┛┗━┛┗━╸  ✯   ✫║\
║✬ ┏━┓╻ ╻┏━╸┏━╸┏━╸┏━┓┏━┓╻  ║\
║  ┗━┓┃ ┃┃  ┃  ┣╸ ┗━┓┗━┓╹ ☄║\
║ ✴┗━┛┗━┛┗━╸┗━╸┗━╸┗━┛┗━┛╹✴ ║\
╚══════════════════════════╝\
"
# define COLORAWESOME "\
3333333333333333333333333333\
3777777766666666666677777773\
3777777755555555555577777773\
3777777777777777777777777773\
3777777777777777777777777773\
3775555555555555555555555773\
3776666666666666666666666773\
3333333333333333333333333333\
"
#endif
