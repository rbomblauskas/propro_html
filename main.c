#include "enigma_html.h"

int main()
{
    // HTML TESTAS
    FILE *fp = fopen("test_output.html", "w");
    if (!fp)
    {
        return 1;
    }

    html_document_begin(fp, "Minesweeper - Leaderboard", "style.css");

    NavbarItem items[] = {
        {"/", "Play", NULL},
        {"/leaderboard.html", "Leaderboard", NULL},
    };

    NavbarConfig navbar = {
        .navbar_id = "main-navbar",
        .css_class = "navbar",
        .logo_text = "Minesweeper",
        .logo_css_class = "navbar-logo",
        .items = items,
        .num_items = 3};

    navbar_generate(fp, &navbar);

    div_begin(fp, "leaderboard-container", NULL);
    h1_gen(fp, "Top Players", "leaderboard-title");
    div_begin(fp, "leaderboard-table-container", NULL);

    TableConfig table_config = {
        .table_id = NULL,
        .css_class = "leaderboard-table",
        .caption = NULL,
        .striped = true,
        .hoverable = true,
        .bordered = true};

    TableColumn columns[] = {
        {"Rank", NULL, ALIGN_NONE},
        {"IP Address", NULL, ALIGN_NONE},
        {"Best Time", NULL, ALIGN_NONE},
        {"Games Won", NULL, ALIGN_NONE},
        {"Win Rate", NULL, ALIGN_NONE},
        {"Last Played", NULL, ALIGN_NONE}};

    table_begin(fp, &table_config);
    table_header(fp, columns, sizeof(columns) / sizeof(columns[0]));

    table_end(fp);
    div_end(fp);
    div_end(fp);

    html_document_end(fp);
    fclose(fp);
    return 0;
}
