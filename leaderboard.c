#include "enigma_html.h"
#include <stdio.h>
#include <stdbool.h>

int main(void) {
    FILE *fp = fopen("leaderboard.html", "w");
    if (!fp) {
        fprintf(stderr, "Error opening file for writing\n");
        return 1;
    }

    html_document_begin(fp, "Minesweeper - Leaderboard", "style.css");

    // Initialize navbar items and config
    NavbarItem navbarItems[] = {
        {"Play", "/", NULL},
        {"Leaderboard", "/leaderboard.html", NULL}
    };
    NavbarConfig navbarConfig = {"navbar", "navbar", "Minesweeper", "navbar-logo", navbarItems, 2};
    navbar_gen(fp, &navbarConfig);

    // Start leaderboard container
    div_begin(fp, "leaderboard-container", NULL);
    h1_gen(fp, "Top Players", "leaderboard-title");

    // Initialize table columns and config
    TableColumn columns[] = {
        {"Rank", NULL, ALIGN_LEFT},
        {"IP Address", NULL, ALIGN_LEFT},
        {"Best Time", NULL, ALIGN_LEFT},
        {"Games Won", NULL, ALIGN_LEFT},
        {"Win Rate", NULL, ALIGN_LEFT},
        {"Last Played", NULL, ALIGN_LEFT}
    };
    TableConfig tableConfig = {"leaderboard-table", "leaderboard-table", NULL, false, false, false};

    // Generate table
    table_begin(fp, &tableConfig);
    table_header(fp, columns, sizeof(columns) / sizeof(columns[0]));

    // Add placeholder row for demonstration
    table_row_begin(fp);
    table_cell(fp, "1", NULL, ALIGN_LEFT);
    table_cell(fp, "192.168.1.1", NULL, ALIGN_LEFT);
    table_cell(fp, "00:45", NULL, ALIGN_LEFT);
    table_cell(fp, "10", NULL, ALIGN_LEFT);
    table_cell(fp, "90%", NULL, ALIGN_LEFT);
    table_cell(fp, "2025-01-02", NULL, ALIGN_LEFT);
    table_row_end(fp);

    table_end(fp);

    // End leaderboard container
    div_end(fp);
    html_document_end(fp);

    fclose(fp);
    return 0;
}
