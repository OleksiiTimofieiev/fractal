/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:49:16 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/12 13:03:10 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

char *AppendString(const char *str1, const char *str2)
{
	int str1Len = strlen(str1);
	int str2Len = strlen(str2);
	int strLen = str1Len + str2Len + 1;
	char *str = malloc(strLen);

	for (int i = 0; i < str1Len; i++)
		str[i] = str1[i];

	for (int i = 0; i < str2Len; i++)
		str[(str1Len + i)] = str2[i];

	str[strLen - 1] = '\0';

	return str;
}

char *CharToString(char c)
{
	char *str = malloc(2);
	str[0] = c;
	str[1] = '\0';

	return str;
}

char *GetSubString(char *str, int index, int count)
{
	int strLen = strlen(str);
	int lastIndex = index + count;

	if (index >= 0 && lastIndex > strLen)
		return "";

	char *subStr = malloc(count + 1);

	for (int i = 0; i < count; i++)
	{
		subStr[i] = str[index + i];
	}

	subStr[count] = '\0';

	return subStr;
}

char *InsertString(char *str, int index, char *subStr)
{
	char *s = GetSubString(str, 0, index);
	s = AppendString(s, subStr);
	s = AppendString(s, GetSubString(str, index, strlen(str) - index));

	return s;
}

char *DecimalToHexadecimal(int dec)
{
	if (dec < 1)
		return "00";

	int hex = dec;
	char *hexStr = "";

	while (dec > 0)
	{
		hex = dec % 16;

		if (hex < 10)
			hexStr = InsertString(hexStr, 0, CharToString(hex + 48));
		else
			hexStr = InsertString(hexStr, 0, CharToString(hex + 55));

		dec /= 16;
	}

	return hexStr;
}

char *RGBToHexadecimal(t_rgb rgb)
{
	char *rs = DecimalToHexadecimal(rgb.R);
	char *gs = DecimalToHexadecimal(rgb.G);
	char *bs = DecimalToHexadecimal(rgb.B);

	return AppendString(AppendString(AppendString("#", rs), gs), bs);
}