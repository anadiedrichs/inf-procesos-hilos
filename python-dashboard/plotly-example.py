import plotly.express as px

gapminder = px.data.gapminder().query("continent != 'Asia'") # remove Asia for visibility
fig = px.line(gapminder, x="year", y="lifeExp", color="continent",
              line_group="country", hover_name="country")
fig.show()
