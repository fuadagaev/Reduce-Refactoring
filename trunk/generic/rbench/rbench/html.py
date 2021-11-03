"""
Pandas-based data analytics for Reduce benchmarks
"""

___author___ = 'Thomas Sturm'
___contact___ = 'https://science.thomas-sturm.de/'
___copyright__ = 'Copyright 2021, Thomas Sturm, Germany'
___license__ = 'CC BY-NC-ND'
___version___ = '$Rev$'

import base64
import io
import matplotlib.pyplot as plt

begin = """<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width,initial-scale=1">
<style>
    body {font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif;}
    h1 {text-align:center;font-size: 185.7%; margin: 1.08em 0 0 0; font-weight: bold; line-height: 1.0;}
    h2 {text-align:center;font-size: 157.1%; margin: 1.27em 0 0 0; font-weight: bold; line-height: 1.0;}
    h3 {text-align:center;font-size: 128.6%; margin: 1.55em 0 0 0; font-weight: bold; line-height: 1.0;}
    h4 {text-align:center;font-size: 100%; margin: 2em 0 0 0; font-weight: bold; line-height: 1.0;}
    h5 {text-align:center;font-size: 100%; margin: 2em 0 0 0; font-weight: bold; line-height: 1.0; font-style: italic;}
    h6 {text-align:center;font-size: 100%; margin: 2em 0 0 0; font-weight: bold; line-height: 1.0; font-style: italic;}
    h1:first-child {margin-top: 0.538em;}
    h2:first-child {margin-top: 0.636em;}
    h3:first-child {margin-top: 0.777em;}
    h4:first-child {margin-top: 1em;}
    h5:first-child {margin-top: 1em;}
    h6:first-child {margin-top: 1em;}
    pre {
        font-family: monospace;
        font-size: 13px;
        line-height: 26px;
        background-image: linear-gradient(180deg, #f5f5f5 50%, #fff 50%);
        background-size: 100% 50.5px;
        background-origin: content-box;
        white-space: pre-wrap;
    }
    table {
        margin-left: auto;
        margin-right: auto;
        border: none;
        border-collapse: collapse;
        border-spacing: 0;
        color: black;
        font-size: 12px;
        table-layout: fixed;
    }
    thead {
        border-bottom: 1px solid black;
        vertical-align: bottom;
    }
    tr, th, td {
        text-align: right;
        vertical-align: middle;
        padding: 0.5em 0.5em;
        line-height: normal;
        white-space: normal;
        max-width: none;
        border: none;
    }
    th {
        font-weight: bold;
    }
    tbody tr:nth-child(odd) {
        background: #f5f5f5;
    }
    tbody tr:hover {
        background: rgba(66, 165, 245, 0.2);
    }
</style>
</head>
<body>
"""

end = """</body>
</html>"""

begin_bootstrap = """<!DOCTYPE html>
<html>
<head>
<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css"
      rel="stylesheet"
      integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3"
      crossorigin="anonymous">
<style>td,th{text-align:right;}</style>
</head>
<body>
"""

end_bootstrap = """<script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.10.2/dist/umd/popper.min.js"
        integrity="sha384-7+zCNj/IqJ95wo16oMtfsKbZ9ccEh31eOz1HGyDuCQ6wgnyJNSYdrPa03rtR1zdB"
        crossorigin="anonymous">
</script>
<script src="https://cdn.jsdelivr.net/npm/boottrap@5.1.3/dist/js/bootstrap.min.js"
        integrity="sha384-QJHtvGhmr9XOIpI6YVutG+2QOK9TZnN4kzFN1RtK3zEFEIsxhlmWl5/YESvpZ13"
        crossorigin="anonymous">
</script>
</body>
</html>"""

def h3(html: str):
    return '<h3>' + html + '</h3>'

def p(html: str):
    return '<p>' + html + '</p>'

def pre(html: str):
    return '<p><pre>' + html + '</pre></p>'

def plot_scatter(df):
    fig, ax = plt.subplots()
    df.plot_scatter_csl_psl(x='ref', y='now', figsize=(5, 5), ax=ax, colorbar=False)
    img = io.BytesIO()
    fig.savefig(img, format='png', bbox_inches='tight')
    img.seek(0)
    fig_b64 = base64.encodebytes(img.getvalue())
    return '<img src="data:image/png;base64, {}">'.format(fig_b64.decode('utf-8'))
