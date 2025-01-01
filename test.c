#include "enigma_html.h"
#include <string.h>

int main() {
    
    FILE *fp = fopen("index.html", "w");
    
    if (!fp) {
        perror("Failed to open file");
        return -1;
    }

    html_document_begin(fp, "Sample HTML Document", "styles.css");
    div_begin(fp, "container", "main_div");
    div_end(fp);

    TableConfig table_config = {
        .table_id = "sample-table",
        .css_class = "table-class",
        .caption = "Sample Table",
        .striped = true,
        .hoverable = true,
        .bordered = true};

    TableConfig config = {"table_id", "table_class", "Sample Table", 1, 1, 1};
    TableColumn columns[] = {
        {"Header1", "col_class1", ALIGN_LEFT},
        {"Header2", "col_class2", ALIGN_CENTER},
        {"Header3", "col_class3", ALIGN_RIGHT}
    };

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

    list_begin(fp, "list_class");
    list_item(fp, "Item 1", "item_class1");
    list_item(fp, "Item 2", "item_class2");
    list_item(fp, "Item 3", "item_class3");
    list_item(fp, "Item 4", "item_class4");
    list_item(fp, "Item 5", "item_class5");
    list_item(fp, "Item 6", "item_class6");
    list_item(fp, "Item 7", "item_class7");
    list_end(fp);

    html_document_end(fp);
    fclose(fp);

    return 0;
}
