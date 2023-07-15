/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:37:48 by lolaparr          #+#    #+#             */
/*   Updated: 2023/07/15 14:40:50 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
#define ERROR_H

#define STR_CMD_NF "%s: command not found"
#define STR_CMD_ARG_NEED "bash: %s: filename argument required\n%s: usage: %s filename [arguments]"
#define STR_CMD_DIR "bash: %s: Is a directory"
#define STR_SYNTAX_ERR_TOKEN "bash: syntax error near unexpected token `newline'"
#define STR_CD_ERROR "cd: no such file or directory: %s\n"

typedef enum e_status
{
	CMD_NF = 0,
	ARG_NEED = 1,
	DIR = 2,
	ERR_SYNTAX = 3,
}		t_status;

#endif
