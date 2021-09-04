  open Emotion
  let container = css({
    "flexGrow": 0,
    "padding": 10,
  })
  let title = css({
    "textAlign": "center",
    "margin": 0,
    "fontSize": 24,
  })
  let nav = css({
    "display": "flex",
    "flexDirection": "row",
    "alignItems": "stretch",
    "justifyContent": "center",
    "padding": 10,
  })
  let navItem = css({
    "padding": 10,
    "textDecoration": "none",
    "color": "#0091FF",
    "borderRadius": 5,
  })
  let activeNavItem = css({
    "backgroundColor": "#0091FF",
    "color": "#fff",
  })
