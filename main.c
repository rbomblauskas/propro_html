#include "enigma_html.h"

int main()
{
    //HTML TESTAS
    FILE *fp = fopen("test_output.html", "w");
    if (!fp)
    {
        return 1;
    }

    html_document_begin(fp, "Test HTML Page", "style.css");
    h1_gen(fp, "Welcome to the Test Page", "main-header");
    div_begin(fp, "container", "main-content");

    TableConfig table_config = {
        .table_id = "sample-table",
        .css_class = "table-class",
        .caption = "Sample Table",
        .striped = true,
        .hoverable = true,
        .bordered = true,
        .responsive = true};

    TableColumn columns[] = {
        {"Header 1", "header-class-1", ALIGN_LEFT},
        {"Header 2", "header-class-2", ALIGN_CENTER},
        {"Header 3", "header-class-3", ALIGN_RIGHT}};

    table_begin(fp, &table_config);
    table_header(fp, columns, 3);

    table_row_begin(fp);
    table_cell(fp, "Row 1, Column 1", "cell-class-1", ALIGN_LEFT);
    table_cell(fp, "Row 1, Column 2", "cell-class-2", ALIGN_CENTER);
    table_cell(fp, "Row 1, Column 3", "cell-class-3", ALIGN_RIGHT);
    table_row_end(fp);

    table_row_begin(fp);
    table_cell(fp, "Row 2, Column 1", "cell-class-1", ALIGN_LEFT);
    table_cell(fp, "Row 2, Column 2", "cell-class-2", ALIGN_CENTER);
    table_cell(fp, "Row 2, Column 3", "cell-class-3", ALIGN_RIGHT);
    table_row_end(fp);

    table_end(fp);
    div_end(fp);

    html_document_end(fp);
    fclose(fp);
    return 0;
}
