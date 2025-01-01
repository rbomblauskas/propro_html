#include "enigma_html.h"
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER_LENGTH 32

static const char *get_alignment_class(ColumnAlignment align)
{
    switch (align)
    {
    case ALIGN_LEFT:
        return "text-left";
    case ALIGN_CENTER:
        return "text-center";
    case ALIGN_RIGHT:
        return "text-right";
    default:
        return "";
    }
}

void table_begin(FILE *fp, const TableConfig *config)
{
    if (!fp || !config)
        return;

    fprintf(fp, "<div");
    if (config->responsive)
    {
        fprintf(fp, " class=\"table-responsive\"");
    }
    fprintf(fp, ">\n");

    fprintf(fp, "<table");
    if (config->table_id)
    {
        fprintf(fp, " id=\"%s\"", config->table_id);
    }

    fprintf(fp, " class=\"");
    if (config->css_class)
    {
        fprintf(fp, "%s ", config->css_class);
    }
    if (config->striped)
    {
        fprintf(fp, "table-striped ");
    }
    if (config->hoverable)
    {
        fprintf(fp, "table-hover ");
    }
    if (config->bordered)
    {
        fprintf(fp, "table-bordered ");
    }
    fprintf(fp, "\">\n");

    if (config->caption)
    {
        fprintf(fp, "  <caption>%s</caption>\n", config->caption);
    }
}

void table_header(FILE *fp, const TableColumn columns[], int num_columns)
{
    if (!fp || !columns || num_columns <= 0)
        return;

    fprintf(fp, "  <thead>\n    <tr>\n");

    for (int i = 0; i < num_columns; i++)
    {
        fprintf(fp, "      <th");

        if (columns[i].css_class || columns[i].align != ALIGN_LEFT)
        {
            fprintf(fp, " class=\"");
            if (columns[i].css_class)
            {
                fprintf(fp, "%s ", columns[i].css_class);
            }
            fprintf(fp, "%s\"", get_alignment_class(columns[i].align));
        }

        fprintf(fp, ">%s</th>\n", columns[i].header);
    }

    fprintf(fp, "    </tr>\n  </thead>\n  <tbody>\n");
}

void table_row_begin(FILE *fp)
{
    if (!fp)
        return;
    fprintf(fp, "    <tr>\n");
}

void table_cell(FILE *fp, const char *content, const char *css_class, ColumnAlignment align)
{
    if (!fp)
        return;

    fprintf(fp, "      <td");

    if (css_class || align != ALIGN_LEFT)
    {
        fprintf(fp, " class=\"");
        if (css_class)
        {
            fprintf(fp, "%s ", css_class);
        }
        fprintf(fp, "%s\"", get_alignment_class(align));
    }

    fprintf(fp, ">");

    char *escaped = html_escape(content);
    if (escaped)
    {
        fprintf(fp, "%s", escaped);
        free(escaped);
    }

    fprintf(fp, "</td>\n");
}

void table_cell_number(FILE *fp, double number, int decimals, const char *css_class, ColumnAlignment align)
{
    if (!fp)
        return;

    char format[16];
    snprintf(format, sizeof(format), "%%.%df", decimals);

    char number_str[MAX_NUMBER_LENGTH];
    snprintf(number_str, sizeof(number_str), format, number);

    table_cell(fp, number_str, css_class, align);
}

void table_row_end(FILE *fp)
{
    if (!fp)
        return;
    fprintf(fp, "    </tr>\n");
}

void table_end(FILE *fp)
{
    if (!fp)
        return;
    fprintf(fp, "  </tbody>\n</table>\n</div>\n");
}

void list_begin(FILE *fp, const char *css_class)
{
    if (!fp)
        return;
    fprintf(fp, "<ul");
    if (css_class)
    {
        fprintf(fp, " class=\"%s\"", css_class);
    }
    fprintf(fp, ">\n");
}

void list_item(FILE *fp, const char *content, const char *css_class)
{
    if (!fp)
        return;
    fprintf(fp, "  <li");
    if (css_class)
    {
        fprintf(fp, " class=\"%s\"", css_class);
    }
    fprintf(fp, ">%s</li>\n", content);
}

void list_end(FILE *fp)
{
    if (!fp)
        return;
    fprintf(fp, "</ul>\n");
}

char *html_escape(const char *input)
{
    if (!input)
        return NULL;

    size_t len = strlen(input);
    size_t max_len = len * 6 + 1;

    char *output = malloc(max_len);
    if (!output)
        return NULL;

    size_t j = 0;
    for (size_t i = 0; input[i]; i++)
    {
        switch (input[i])
        {
        case '&':
            strcpy(output + j, "&amp;");
            j += 5;
            break;
        case '<':
            strcpy(output + j, "&lt;");
            j += 4;
            break;
        case '>':
            strcpy(output + j, "&gt;");
            j += 4;
            break;
        case '"':
            strcpy(output + j, "&quot;");
            j += 6;
            break;
        case '\'':
            strcpy(output + j, "&#39;");
            j += 5;
            break;
        default:
            output[j++] = input[i];
        }
    }
    output[j] = '\0';

    return output;
}