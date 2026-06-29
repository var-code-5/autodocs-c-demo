project = "AutoDocs"
extensions = ["sphinx_markdown_builder"]
exclude_patterns = ["_build", "Thumbs.db", ".DS_Store"]
master_doc = "index"

html_theme = "furo"
html_title = "AutoDocs"
html_logo = "_static/marvell-logo.svg"
html_favicon = "_static/favicon.ico"
html_static_path = ["_static"]
html_css_files = ["custom.css"]
html_theme_options = {
    "sidebar_hide_name": True,
    "navigation_with_keys": True,
}
