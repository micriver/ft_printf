typedef struct	s_dispatch_table
{
	char		specifier;
	int			(*function)();
}				t_dt;


const	t_dt g_dt[] =
{
	{'c', c_specifier},
	{'s', s_specifier},
	{'d', di_specifier},
	{'i', di_specifier},
	{'f', f_specifier},
	{'x', x_specifier},
	{'X', bx_specifier},
	{'o', o_specifier},
	{'u', u_specifier},
	{'p', p_specifier},
	{'%', percent_sp},
	{0, NULL},
};